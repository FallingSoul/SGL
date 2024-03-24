#ifndef __SGL_CORE_GRAPHICS_VULKAN_INSTANCE_LAYER__
#define __SGL_CORE_GRAPHICS_VULKAN_INSTANCE_LAYER__


#include "sgl/core/family.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                class SGL_API sglVkInstanceLayer
                {
                public:
                    sglVkInstanceLayer();
                    sglVkInstanceLayer(const sglChar * name);
                    sglVkInstanceLayer(sglInt index);
                    sglVkInstanceLayer(const sglVkInstanceLayer & layer);
                    ~sglVkInstanceLayer();
                    
                    sglConfigInfo get_config()const;
                    sglConfigInfo get_config_impl()const;
                    const sglChar * get_description()const;
                    sglBool valid()const;
                    sglBool invalid()const;
                    sglVkInstanceLayer next()const;
                    sglInt index()const;

                    sglBool operator ==(const sglVkInstanceLayer & layer)const;
                    const sglVkInstanceLayer & operator =(const sglVkInstanceLayer & layer);
                    const sglVkInstanceLayer & operator ++();
                    static sglInt count();
                private:
                    struct sglVkInstanceLayer_Impl * _layer;
                };
            }
        }
    }
}
#endif //!__SGL_CORE_GRAPHICS_VULKAN_INSTANCE_LAYER__