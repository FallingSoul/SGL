
#include <glad/gl.h>
#include "sgl/core/assert.h"
#include "sgl/framework/application.h"

namespace sgl
{
	sglApplication* sglApplication::_application = nullptr;
	struct sglApplicationInfo
	{
		std::unique_ptr<sglOnEventCallback<sglApplication>> on_event_callback = nullptr;
		sglRef<sglWindow> window;
		sglRef<sglLayerStack> layer_stack;


		// Graphics
		sglRef<sglGraphicsContext> graphics_context;
		sglRef<sglRendererAPI> renderer_api;
		sglRef<sglRenderer> renderer;
	};
	sglApplication* sglApplication::get_application()
	{
		return sglApplication::_application;
	}
	sglRef<sglWindow> sglApplication::get_window()
	{
		return this->_info->window;
	}
	sglRef<sglGraphicsContext> sglApplication::get_graphics_context()
	{
		return this->_info->graphics_context;
	}
	sglRef<sglLayerStack> sglApplication::get_layer_stack()
	{
		return this->_info->layer_stack;
	}
	sglRef<sglRendererAPI> sglApplication::get_renderer_api()
	{
		return this->_info->renderer_api;
	}
	sglRef<sglRenderer> sglApplication::get_renderer()
	{
		return this->_info->renderer;
	}
	sglApplication::sglApplication()
	{
		SGL_ASSERT(_application == nullptr,"There is Already an Application!");
		_application = this;
		this->_info.remake();
	}
	sglApplication::~sglApplication()
	{

	}
	void sglApplication::run()
	{
		if (this->_info->window)
		{
			using sglTime_T = sglLayer::sglLayerTime;
			sglTime_T last_time = sglTime_T::now();
			auto& window = this->_info->window;
			while (!window->is_closed())
			{

				window->poll_events();

				// Claer Screen
				auto renderer_api = this->get_renderer_api();
				if (renderer_api)
				{
					renderer_api->clear();
				}

				auto layer_stack = this->get_layer_stack();
				if (layer_stack)
				{
					sglTime_T delta_time = sglTime_T::now(last_time);
					auto it = layer_stack->end();
					do
					{
						it--;
						(*it)->on_update(delta_time);
					} while (it != layer_stack->begin());
				}
				window->swap_buffers();

				// Reset Time
				last_time = sglTime_T::now();
			}
		}
		this->release();
	}
	void sglApplication::init_window(const sglWindowProperties& prop)
	{
		this->_info->window.remake(prop);
		this->_info->on_event_callback = std::make_unique<sglOnEventCallback<sglApplication>>(this);
		this->_info->window->get_callbacks().set_on_event_callback(*this->_info->on_event_callback);
	}
	void sglApplication::init_graphics_context(const sglGraphicsContextProperties& prop)
	{
		this->_info->graphics_context.remake(prop);
	}
	void sglApplication::init_layer_stack(size_t size)
	{
		this->_info->layer_stack.remake(size);
	}
	void sglApplication::init_renderer()
	{
		SGL_ASSERT(this->get_graphics_context(),"Init Graphics Context before Init Renderer!");
		this->_info->renderer_api.remake(*this->get_graphics_context());
		this->_info->renderer.remake(this->get_renderer_api());

		// Set Clear Color
		this->_info->renderer_api->set_clear_color(0.0f,0.0f,0.0f,1.0f);
	}
	void sglApplication::release()
	{
		this->_info->layer_stack.reset();
		this->_info->on_event_callback.reset();
		this->_info->window.reset();
	}
}