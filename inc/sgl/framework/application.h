#ifndef __SGL_FRAMEWORK_APPLICATION__
#define __SGL_FRAMEWORK_APPLICATION__

#include "sgl/core.h"
#include "sgl/core/window.h"
#include "sgl/core/renderer.h"
#include "sgl/framework/layer_stack.h"

namespace sgl
{
	struct sglWindowProperties;
	class sglPlatformWindow;

	class SGL_API sglApplication
	{
	public:
		sglApplication();
		virtual ~sglApplication();
		void run();
	protected:
		void init_window(const sglWindowProperties& prop);
		void init_layer_stack(size_t size = 1);
		void init_graphics_context(const sglGraphicsContextProperties& prop);
		void init_renderer();
	private:
		void release();
	public:
		sglRef<sglLayerStack> get_layer_stack();
		sglRef<sglWindow> get_window();
		sglRef<sglGraphicsContext> get_graphics_context();
		sglRef<sglRendererAPI> get_renderer_api();
		sglRef<sglRenderer> get_renderer();
	public:
		static sglApplication* get_application();
	public:
		template<class E>
		void on_event(E& e)
		{
			sglEventDispatcher dispatcher(e);
			
			auto layer_stack = this->get_layer_stack();
			if (layer_stack)
				for (auto layer : *layer_stack)
					layer->on_event(e);
					
		}
	private:
		sglUnique<struct sglApplicationInfo> _info;
	private:
		static sglApplication* _application;
	};
	extern sglApplication* sglCreateApplication();
	extern void sglReleaseApplication(sglApplication* app);
}


#endif //!__SGL_FRAMEWORK_APPLICATION__