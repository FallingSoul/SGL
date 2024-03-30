#ifndef __SGL_CORE_GRAPHICS_VULKAN_INSTANCE_EXTENSION__
#define __SGL_CORE_GRAPHICS_VULKAN_INSTANCE_EXTENSION__

#include "sgl/core/family.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkInstanceExtension
                {
                    const sglChar * name;
                    sglInt version_major,version_minor,version_patch;
                };
                class SGL_API sglVkInstanceExtensions
                {
                public:
                    const sglVkInstanceExtensions & operator =(const sglVkInstanceExtensions & extensions);
                    sglVkInstanceExtensions(const sglVkInstanceExtensions & extensions);
                    sglVkInstanceExtensions();
                    ~sglVkInstanceExtensions();

                    sglBool existent(const sglChar * name)const;
                    sglInt find(const sglChar * name)const;
                    sglInt count()const;
                    sglVkInstanceExtension at(sglInt index)const;
                    sglVkInstanceExtension at(const sglChar * name)const;
                    sglVkInstanceExtension operator [](sglInt index)const;
                    sglVkInstanceExtension operator [](const sglChar * name)const;
                private:
                    struct sglVkInstanceExtensions_Impl * _extensions;
                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_VULKAN_INSTANCE_EXTENSION__