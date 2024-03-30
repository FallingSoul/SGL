

#include <iostream>
#include <thread>
#include "sgl/sgl.h"
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <glm/glm.hpp>

int main()
{
    printf("Startup time: %gsec\n",clock() / 1000.);
    printf("argc = %d\n",this->get_count());
    for(sglInt index = 0;index < this->get_count();index++)
    {
        printf("argv[%d] = %s\n",index,this->get_arg(index));
    }
    sglInt count = 0;
    const sglChar ** extensions = core::graphics::window::sglWindow::required_extensions(&count);
    core::graphics::vulkan::sglVkInstanceExtensions all_extensions;
    printf("All extensions: %d\n",all_extensions.count());
    for(sglInt index = 0;index < all_extensions.count();index++)
    {
        auto ext = all_extensions[index];
        printf("%s %d.%d.%d\n",ext.name,ext.version_major,ext.version_minor,ext.version_patch);
    }
    core::graphics::vulkan::sglVkInstanceLayers all_layers;
    printf("All layers: %d\n",all_layers.count());
    for(sglInt index = 0;index < all_layers.count();index++)
    {
        auto ext = all_layers[index];
        printf("%s %d.%d.%d\n",ext.name,ext.version_major,ext.version_minor,ext.version_patch);
    }
    core::graphics::vulkan::sglVkInstance instance({"Hello Vulkan!",0,0,1},extensions,count,"VK_LAYER_KHRONOS_validation");
    core::graphics::vulkan::sglVkDebugMessenger messenger(instance);
    printf("Finished! %gsec\n",clock() / 1000.);
    return 0;
}