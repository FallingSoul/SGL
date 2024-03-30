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
                    struct sglUserPointer
                    {
                        sglWindow * window;
                        sglVoid * ptr;
                    }user_ptr;
                    class sglWindowErrorCallback
                    {
                    public:
                        static sglVoid error_callback(sglInt code,const sglChar * desc)
                        {
                            throw sglException(desc,code);
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
                    :_window(new sglWindow_Impl)
                {
                    this->_window->user_ptr.window = this;
                    this->_window->user_ptr.ptr = nullptr;
                    this->_window->name = name;
                    sglInt width,height;
                    default_size(width,height);
                    this->_window->window = glfwCreateWindow(width,height,name,nullptr,nullptr);
                    glfwSetWindowUserPointer(this->_window->window,&this->_window->user_ptr);
                }
                sglWindow::sglWindow(const sglChar * name,sglInt width,sglInt height)
                    :_window(new sglWindow_Impl)
                {
                    this->_window->user_ptr.window = this;
                    this->_window->user_ptr.ptr = nullptr;
                    this->_window->name = name;
                    this->_window->window = glfwCreateWindow(width,height,name,nullptr,nullptr);
                    glfwSetWindowUserPointer(this->_window->window,&this->_window->user_ptr);
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
                sglKetStatus sglWindow::get_key(sglKeyCode code)const
                {
                    int status = glfwGetKey(this->_window->window,int(code));
                    return GLFW_RELEASE == status ? sglKetStatus::Release :
                    GLFW_PRESS == status ? sglKetStatus::Press :
                    GLFW_REPEAT == status ? sglKetStatus::Repeat :
                    sglKetStatus::Invalid;
                }
                sglVoid sglWindow::get_size(sglInt & width,sglInt & height)const
                {
                    glfwGetWindowSize(this->_window->window,&width,&height);
                }
                sglVoid sglWindow::get_frame_size(sglInt & left,sglInt & top,sglInt & right,sglInt & bottom)const
                {
                    glfwGetWindowFrameSize(this->_window->window,&left,&top,&right,&bottom);
                }
                sglVoid sglWindow::set_user_pointer(sglVoid * ptr)
                {
                    this->_window->user_ptr.ptr = ptr;
                }
                sglVoid * sglWindow::get_user_pointer()const
                {
                    return this->_window->user_ptr.ptr;
                }
                
                sglVoid sglWindow::poll_event()
                {
                    glfwPollEvents();
                }
                sglVoid sglWindow::poll_event(sglDouble seconds)
                {
                    sglDouble begin = glfwGetTime();
                    while(glfwGetTime() - begin < seconds)glfwPollEvents();
                }
                sglVoid sglWindow::wait_event()
                {
                    glfwWaitEvents();
                }
                sglVoid sglWindow::wait_event(sglDouble time_out_seconds)
                {
                    glfwWaitEventsTimeout(time_out_seconds);
                }
                sglVoid sglWindow::default_size(sglInt & width,sglInt & height)
                {
                    width = 1280;
                    height = 720;
                }
                const sglChar ** sglWindow::required_extensions(sglInt * count)
                {
                    uint32_t _count_ = 0;
                    const sglChar ** extensions = glfwGetRequiredInstanceExtensions(&_count_);
                    if(count)*count = _count_;
                    return extensions;
                }
                
            }
        }
    }
}