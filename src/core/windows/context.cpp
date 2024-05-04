#include <GLFW/glfw3.h>
#include "sgl/core/windows/context.h"


namespace sgl
{
    namespace core {
        void sglWindowContext::error_callback(int code, const char * errstr)
        {
            throw sglException(errstr,code);
        }
        sglWindowContext::sglWindowContext()
        {
            glfwSetErrorCallback(error_callback);
            glfwInit();
            glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
            glfwWindowHint(GLFW_VISIBLE,GLFW_FALSE);
        }
        sglWindowContext::sglWindowContext(sglInt opengl_major,sglInt opengl_minor)
        {
            glfwSetErrorCallback(error_callback);
            glfwInit();
            glfwWindowHint(GLFW_CLIENT_API,GLFW_OPENGL_API);
            glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
            glfwWindowHint(GLFW_VISIBLE,GLFW_FALSE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,opengl_major);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,opengl_minor);
            glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_ANY_PROFILE);
        }
        sglWindowContext::~sglWindowContext()
        {
            glfwTerminate();
        }
        sglVoid sglWindowContext::poll_events()
        {
            (void)this; // for static warning
            glfwPollEvents();
        }
        sglDouble sglWindowContext::get_time()
        {
            (void)this; // for static warning
            return glfwGetTime();
        }
    }
}

