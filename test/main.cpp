#include <iostream>
#include "sgl/sgl.h"
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <glm/glm.hpp>
int main()
{
    sgl::core::graphics::window::sglWindow window("Hello World!");
    window.show();
    while(!window.is_closed())window.poll_event();
    


    return 0;
}