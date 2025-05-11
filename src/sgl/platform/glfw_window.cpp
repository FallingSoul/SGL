#include <GLFW/glfw3.h>
#include "sgl/utils/log.h"
#include "sgl/platform/glfw_window.h"
#include "sgl/platform/keymap.h"

namespace sgl
{

	__sgl_Self__<sglWindow> sglWindow::create(const sglWindowProperties& prop)
	{
		return __sgl_Self__<sglWindow>::make<sglGlfwWindow>(prop);
	}

	static class sglGlfwInitializer
	{
	public:
		static void error_callback(int err,const char* desc)
		{
			SGL_LOG_E("GLFW error {}: {}",err,desc);
		}
		sglGlfwInitializer()
		{
			glfwInit();
			glfwSetErrorCallback(error_callback);
		}
		~sglGlfwInitializer()
		{
			glfwTerminate();
		}
	}__sgl_glfw_initializer__;
	struct sglGlfwWindowInfo
	{
		GLFWwindow* window;
		sglGlfwWindow* _this_;
	};
	sglGlfwWindow::sglGlfwWindow(const sglWindowProperties& prop)
		:sglWindow(__sglImplConstruction__{}),_info(new sglGlfwWindowInfo{})
	{
		this->_info->_this_ = this;
		this->_create(prop);
	}
	sglGlfwWindow::~sglGlfwWindow()
	{
		if (this->_info)
		{
			if (this->_info->window)
				glfwDestroyWindow(this->_info->window);
			delete this->_info;
			this->_info = nullptr;
		}
	}
	void sglGlfwWindow::_setup_callbacks()
	{
		glfwSetWindowCloseCallback(this->_info->window, [](GLFWwindow* window)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglWindowClose close(event::sglWindowCloseInfo{});
				pinfo->_this_->event_proc(close);
			});
		glfwSetWindowSizeCallback(this->_info->window, [](GLFWwindow* window, int width, int height)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglWindowResize resize(event::sglWindowResizeInfo{.width = static_cast<float>(width),.height = static_cast<float>(height)});
				pinfo->_this_->event_proc(resize);
			});
		glfwSetWindowFocusCallback(this->_info->window, [](GLFWwindow* window,int status)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglWindowFocus focus(event::sglWindowFocusInfo{.focused = (GLFW_TRUE == status)});
				pinfo->_this_->event_proc(focus);
			});
		glfwSetWindowPosCallback(this->_info->window, [](GLFWwindow* window, int x, int y)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglWindowMove move(event::sglWindowMoveInfo{ .x = static_cast<float>(x),.y = static_cast<float>(y) });
				pinfo->_this_->event_proc(move);
			});
		glfwSetKeyCallback(this->_info->window, [](GLFWwindow* window,int vkey,int scancode,int action,int mods) 
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				sglKeyCodeValue keycode = sglMapKey(vkey);
				sglModifierKeys modkeys = sglMapMods(mods);
				switch (action)
				{
				case GLFW_PRESS:
				{
					event::sglKeyPressed pressed(event::sglKeyPressedInfo{.key = keycode,.mods = modkeys});
					pinfo->_this_->event_proc(pressed);
				}
					break;
				case GLFW_RELEASE:
				{
					event::sglKeyReleased released(event::sglKeyReleasedInfo{ .key = keycode,.mods = modkeys });
					pinfo->_this_->event_proc(released);
				}
					break;
				case GLFW_REPEAT:
				{
					// TODO
				}
					break;
				}
			});
		glfwSetMouseButtonCallback(this->_info->window, [](GLFWwindow* window, int button, int action, int mods)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				sglMouseKeyCode keycode = sglMapMouseKey(button);
				sglModifierKeys modkeys = sglMapMods(mods);
				switch (action)
				{
				case GLFW_PRESS:
				{
					event::sglMousePressed pressed(event::sglMousePressedInfo{.key = keycode,.mods = modkeys});
					pinfo->_this_->event_proc(pressed);
				}
					break;
				case GLFW_RELEASE:
				{
					event::sglMouseReleased released(event::sglMouseReleasedInfo{ .key = keycode,.mods = modkeys });
					pinfo->_this_->event_proc(released);
				}
					break;
				}
			});
		glfwSetCursorPosCallback(this->_info->window, [](GLFWwindow* window, double x, double y)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglMouseMove move(event::sglMouseMoveInfo{ .x = static_cast<float>(x),.y = static_cast<float>(y) });
				pinfo->_this_->event_proc(move);
			});
		glfwSetScrollCallback(this->_info->window, [](GLFWwindow* window, double x, double y)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglMouseScroll scroll(event::sglMouseScrollInfo{ .delta_x = static_cast<float>(x),.delta_y = static_cast<float>(y) });
				pinfo->_this_->event_proc(scroll);
			});
		glfwSetCharCallback(this->_info->window, [](GLFWwindow* window, unsigned int code)
			{
				auto* pinfo = static_cast<sglGlfwWindowInfo*>(glfwGetWindowUserPointer(window));
				event::sglKeyTyped typed(event::sglKeyTypedInfo{.code = code});
				pinfo->_this_->event_proc(typed);
			});
	}
	void sglGlfwWindow::_create(const sglWindowProperties& prop) 
	{
		if (this->_info->window)glfwDestroyWindow(this->_info->window);
		this->_info->window = glfwCreateWindow(prop.width,prop.height, prop.name,nullptr,nullptr);
		glfwSetWindowUserPointer(this->_info->window,this->_info);
		glfwMakeContextCurrent(this->_info->window);
		this->_setup_callbacks();


		// LOG
		int win_x, win_y;
		glfwGetWindowPos(this->_info->window,&win_x,&win_y);
		SGL_LOG_T("Create a {}x{} GLFW window ({}) at ({},{})",
			prop.width,prop.height,(void*)this->_info->window, win_x,win_y);
	}
	void sglGlfwWindow::close() 
	{
		glfwSetWindowShouldClose(this->_info->window,GLFW_TRUE);
	}
	void sglGlfwWindow::show() 
	{
		glfwShowWindow(this->_info->window);
	}
	void sglGlfwWindow::hide() 
	{
		glfwHideWindow(this->_info->window);
	}
	void sglGlfwWindow::poll_events() 
	{
		glfwPollEvents();
	}
	void sglGlfwWindow::swap_buffers()
	{
		glfwSwapBuffers(this->_info->window);
	}
	void sglGlfwWindow::get_cursor_position(float* x, float* y)const
	{
		if (nullptr == x && nullptr == y)return;
		double cx, cy;
		glfwGetCursorPos(this->_info->window, &cx, &cy);
		if (x) *x = static_cast<float>(cx);
		if (y) *y = static_cast<float>(cy);
	}
	void sglGlfwWindow::get_window_size(int* width, int* height) const
	{
		glfwGetWindowSize(this->_info->window,width,height);
	}
	bool sglGlfwWindow::is_closed()const
	{
		return this->_info->window ? (GLFW_FALSE != glfwWindowShouldClose(this->_info->window)) : GLFW_TRUE;
	}

	void* sglGlfwWindow::get_native_handle()
	{
		return this->_info->window;
	}

}