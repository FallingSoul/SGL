#include <string>
#include <GLFW/glfw3.h>
#include "sgl/core/graphics/window/window.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace window
            {
                
                struct sglWindow_Impl
                {
                    GLFWwindow * window;
                    std::string name;
                    class sglWindowErrorCallback
                    {
                    public:
                        static sglVoid error_callback(sglInt code,const sglChar * desc)
                        {
                            throw sglException(desc);
                        }
                    };
                    static class sglWindowInitializer
                    {
                    public:
                        sglWindowInitializer()
                        {
                            glfwSetErrorCallback(sglWindowErrorCallback::error_callback);
                            glfwInit();
                            glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
                            glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
                            glfwWindowHint(GLFW_VISIBLE,GLFW_FALSE);
                        }
                        ~sglWindowInitializer()
                        {
                            glfwTerminate();
                        }
                    }initializer;
                };
                sglWindow_Impl::sglWindowInitializer sglWindow_Impl::initializer;
                sglWindow::sglWindow(const sglChar * name)
                    :_window(nullptr)
                {
                    this->_window = new sglWindow_Impl;
                    this->_window->name = name;
                    this->_window->window = glfwCreateWindow(1280,720,name,nullptr,nullptr);
                }
                sglWindow::~sglWindow()
                {
                    glfwDestroyWindow(this->_window->window);
                    delete this->_window;
                    this->_window = nullptr;
                }
                sglVoid sglWindow::close()
                {
                    glfwSetWindowShouldClose(this->_window->window,GLFW_TRUE);
                }

                sglBool sglWindow::is_closed()const
                {
                    return GLFW_TRUE == glfwWindowShouldClose(this->_window->window);
                }
                const sglChar * sglWindow::name()const
                {
                    return this->_window->name.c_str();
                }
                sglVoid sglWindow::show()
                {
                    glfwShowWindow(this->_window->window);
                }
                sglVoid sglWindow::hide()
                {
                    glfwHideWindow(this->_window->window);
                }
                
                sglVoid sglWindow::poll_event()
                {
                    glfwPollEvents();
                }
                sglVoid sglWindow::wait_event()
                {
                    glfwWaitEvents();
                }
                sglVoid sglWindow::wait_event(sglDouble time_out_seconds)
                {
                    glfwWaitEventsTimeout(time_out_seconds);
                }
            }
        }
    }
}