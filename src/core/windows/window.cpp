#include <GLFW/glfw3.h>
#include "sgl/core/windows/window.h"

namespace sgl
{
    namespace core
    {
        struct sglWindow_Impl
        {
            GLFWwindow * window;
            std::string name;
        };
        sglWindow::sglWindow(const sglChar * name,sglInt width,sglInt height)
        {
            this->window->window = glfwCreateWindow(width,height,name,nullptr,nullptr);
            this->window->name = name;
        }
        sglWindow::~sglWindow()
        {
            glfwDestroyWindow(this->window->window);
        }
        std::string sglWindow::name()const
        {
            return this->window->name;
        }
        sglVoid sglWindow::show()
        {
            glfwShowWindow(this->window->window);
        }
        sglBool sglWindow::shown()const
        {
            return GL_TRUE == glfwGetWindowAttrib(this->window->window,GLFW_VISIBLE);
        }
        sglVoid sglWindow::hide()
        {
            glfwHideWindow(this->window->window);
        }
        sglBool sglWindow::hidden()const
        {
            return GLFW_FALSE == glfwGetWindowAttrib(this->window->window,GLFW_VISIBLE);
        }
        sglVoid sglWindow::close()
        {
            glfwSetWindowShouldClose(this->window->window,GLFW_TRUE);
        }
        sglBool sglWindow::closed()const
        {
            return GLFW_FALSE != glfwWindowShouldClose(this->window->window);
        }
        sglBool sglWindow::key_pressed(sglKeyCode vkey)const
        {
            sglInt k = static_cast<sglInt>(vkey);
            return GLFW_PRESS == glfwGetKey(this->window->window,k);
        }
        sglBool sglWindow::key_released(sglKeyCode vkey)const
        {
            sglInt k = static_cast<sglInt>(vkey);
            return GLFW_RELEASE == glfwGetKey(this->window->window,k);
        }

    }
}
