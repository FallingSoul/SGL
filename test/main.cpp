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
    bool again = false;
    while(!window.is_closed())
    {
        window.poll_event();
        if(!again && sgl::core::graphics::window::sglKetStatus::Press == window.get_key(sgl::core::graphics::window::sglKeyCode::Key_0))
        {
            again = true;
            printf("Pree 0!\n");
        }
        else if(sgl::core::graphics::window::sglKetStatus::Release == window.get_key(sgl::core::graphics::window::sglKeyCode::Key_0))
        {
            again = false;
            printf("Release 0!\n");
        }
    }



    return 0;
}