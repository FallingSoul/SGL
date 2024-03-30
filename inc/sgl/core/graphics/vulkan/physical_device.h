#ifndef __SGL_CORE_GRAPHICS_VULKAN_PHYSICAL_DEVICE__
#define __SGL_CORE_GRAPHICS_VULKAN_PHYSICAL_DEVICE__



#include "sgl/core/family.h"

#include "sgl/core/graphics/vulkan/instance.h"

namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                enum class sglVkPhysicalDeviceType
                {
                    Unknown,
                    Other,
                    Integrated,
                    Discrete,
                    Virtual,
                    CPU
                };
                struct sglVkPhysicalDevice
                {

                };
                class SGL_API sglVkPhysicalDevices
                {
                public:
                private:
                    struct sglVkPhysicalDevices_Impl * _devices;
                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_VULKAN_PHYSICAL_DEVICE__