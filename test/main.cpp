#include <iostream>
#include "sgl/sgl.h"
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>

int main()
{
    glfwInit();
    GLFWwindow * win = glfwCreateWindow(1920,1080,"Hello Vulkan",nullptr,nullptr);
    glfwShowWindow(win);
    
    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);

    while(!glfwWindowShouldClose(win))
    {
        glfwPollEvents();
    }
    return 0;
}