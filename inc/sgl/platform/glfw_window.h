#ifndef __SGL_PLATFORM_GLFW_WINDOW__
#define __SGL_PLATFORM_GLFW_WINDOW__

#include "sgl/core/window.h"

namespace sgl
{
	class SGL_API sglGlfwWindow : public sglWindow
	{
	public:
		sglGlfwWindow(const sglWindowProperties& prop);
		~sglGlfwWindow();
	public:
		//void create(const struct sglWindowProperties& prop);
		void close();
		void show();
		void hide();
		void poll_events();
		void swap_buffers();
		void get_cursor_position(float* x, float* y)const;
		void get_window_size(int* width, int* height)const;
		bool is_closed()const;

		void* get_native_handle();
	private:
		void _setup_callbacks();
		void _create(const sglWindowProperties& prop);
	private:
		struct sglGlfwWindowInfo* _info;
	};
}


#endif //!__SGL_PLATFORM_GLFW_WINDOW__