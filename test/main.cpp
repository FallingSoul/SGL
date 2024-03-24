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
    auto ext = new core::graphics::vulkan::sglVkInstanceExtension[count];
    printf("count: %d\n",count);
    for(sglInt index = 0;index < count;index++)
    {
        core::graphics::vulkan::sglVkInstanceExtension extension = extensions[index];
        ext[index] = extension;
        printf("%d: %s ver %d.%d.%d\n",
            extension.index(),extension.get_config().name,
            extension.get_config().version_major,
            extension.get_config().version_minor,
            extension.get_config().version_patch);
    }
    printf("All: %d\n",core::graphics::vulkan::sglVkInstanceExtension::count());
    for(core::graphics::vulkan::sglVkInstanceExtension extension = 0;extension.valid();extension = extension.next())
    {
        printf("%d: %s ver %d.%d.%d\n",
            extension.index(),extension.get_config().name,
            extension.get_config().version_major,
            extension.get_config().version_minor,
            extension.get_config().version_patch);
    }
    core::graphics::vulkan::sglVkInstance instance({"Vulkan App",0,0,1},ext,count,"VK_LAYER_KHRONOS_validation");
    core::graphics::vulkan::sglVkDebugMessenger messenger(instance);
    core::graphics::vulkan::sglVkPhysicalDevice pdevice(instance,0);

    printf("Physical Device: %d\n",pdevice.count());
    for(;pdevice.valid();++pdevice)
    {
        sglConfigInfo driver = pdevice.get_config_driver();
        sglConfigInfo api = pdevice.get_config_api();
        auto type = pdevice.get_type();
        printf("%s %d.%d.%d %s\n",driver.name,driver.version_major,driver.version_minor,driver.version_patch,
            decltype(type)::Discrete == type ? "Discrete" : decltype(type)::Integrated == type ? "Integrated" : "Unknown");
    }
    printf("Finished!\n");
    delete [] ext;
    return 0;
}