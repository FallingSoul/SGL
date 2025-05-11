#ifndef __SGL_CORE_WINDOW__
#define __SGL_CORE_WINDOW__

#include "sgl/core/event/dispatcher.h"


namespace sgl
{
	struct sglWindowProperties
	{
		const char* name;
		int width, height;
		void* user_ptr;
	};



	class SGL_API sglWindow
	{
	public:
		static __sgl_Self__<sglWindow> create(const sglWindowProperties& prop);
	public:
		sglWindow(const sglWindow&) = delete;
	public:
		sglWindow(const sglWindowProperties& prop)
			:_self(create(prop))
		{
		}
		virtual ~sglWindow() = default;
	protected:
		sglWindow(__sglImplConstruction__):_callbacks(std::make_unique<sglAllEventCallbacks>()){}
	public:
		virtual void close() { this->_self->close(); }
		virtual void show() { this->_self->show(); }
		virtual void hide() { this->_self->hide(); }
		virtual void poll_events() { this->_self->poll_events(); }
		virtual void swap_buffers() { this->_self->swap_buffers(); }
		virtual void get_cursor_position(float* x, float* y)const { this->_self->get_cursor_position(x,y); }
		virtual void get_window_size(int* width, int* height)const { this->_self->get_window_size(width, height); }
		virtual bool is_closed()const { return this->_self->is_closed(); }
		virtual void* get_native_handle() { return this->_self->get_native_handle(); }


		__sgl_Self__<sglWindow>& get_self() { return this->_self; }
		const __sgl_Self__<sglWindow>& get_self()const { return this->_self; }
	public:
		std::pair<int, int> get_window_size()const
		{
			int w,h;
			this->_self->get_window_size(&w,&h);
			return std::pair<int, int>(w,h);
		}
	public:
		sglAllEventCallbacks& get_callbacks() { return *this->_self->_callbacks; }
		
	protected:
		template<class E>
		void event_proc(E& e)
		{
			sglEventDispatcher dispatcher(e);
			dispatcher.dispatch(*this->_callbacks);
		}
	private:
		std::unique_ptr<sglAllEventCallbacks> _callbacks = nullptr;
		__sgl_Self__<sglWindow> _self;
	};

}


#endif //!__SGL_CORE_WINDOW__