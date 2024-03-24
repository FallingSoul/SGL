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
                class SGL_API sglVkPhysicalDevice
                {
                public:
                    sglVkPhysicalDevice(const sglVkInstance & instance);
                    sglVkPhysicalDevice(const sglVkInstance & instance,const sglChar * name);
                    sglVkPhysicalDevice(const sglVkInstance & instance,sglInt index);
                    sglVkPhysicalDevice(const sglVkPhysicalDevice & device);
                    ~sglVkPhysicalDevice();


                    sglConfigInfo get_config_driver()const;
                    sglConfigInfo get_config_api()const;
                    sglVkPhysicalDeviceType get_type()const;
                    sglBool invalid()const;
                    sglBool valid()const;
                    sglVkPhysicalDevice next()const;
                    sglInt index()const;
                    sglBool operator == (const sglVkPhysicalDevice & device);
                    const sglVkPhysicalDevice & operator = (const sglVkPhysicalDevice & device);
                    const sglVkPhysicalDevice & operator ++();
                    sglInt count();
                private:
                    struct sglVkPhysicalDevice_Impl * _device;
                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_VULKAN_PHYSICAL_DEVICE__