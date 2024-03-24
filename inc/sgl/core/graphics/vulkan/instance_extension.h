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
                class SGL_API sglVkInstanceExtension
                {
                public:
                    sglVkInstanceExtension(const sglVkInstanceExtension & ext);
                    sglVkInstanceExtension(sglInt index);
                    sglVkInstanceExtension(const sglChar * name);
                    sglVkInstanceExtension();
                    ~sglVkInstanceExtension();
                    
                    sglConfigInfo get_config()const;
                    sglBool valid()const;
                    sglBool invalid()const;
                    sglVkInstanceExtension next()const;
                    sglInt index()const;

                    sglBool operator ==(const sglVkInstanceExtension & ext)const;
                    const sglVkInstanceExtension & operator =(const sglVkInstanceExtension & ext);
                    const sglVkInstanceExtension & operator ++();
                    static sglInt count();
                private:
                    struct sglVkInstanceExtension_Impl * _extension;
                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_VULKAN_INSTANCE_EXTENSION__