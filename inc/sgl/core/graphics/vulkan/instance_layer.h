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
                struct sglVkInstanceLayer
                {
                    const sglChar * name;
                    const sglChar * description;
                    sglInt version_major,version_minor,version_patch;
                    sglInt implementation_version_major,implementation_version_minor,implementation_version_patch;
                };
                class SGL_API sglVkInstanceLayers
                {
                public:
                    const sglVkInstanceLayers & operator =(const sglVkInstanceLayers & layers);
                    sglVkInstanceLayers(const sglVkInstanceLayers & layers);
                    sglVkInstanceLayers();
                    ~sglVkInstanceLayers();

                    sglBool existent(const sglChar * name)const;
                    sglInt find(const sglChar * name)const;
                    sglInt count()const;
                    sglVkInstanceLayer at(sglInt index)const;
                    sglVkInstanceLayer at(const sglChar * name)const;
                    sglVkInstanceLayer operator [](sglInt index)const;
                    sglVkInstanceLayer operator [](const sglChar * name)const;
                private:
                    struct sglVkInstanceLayers_Impl * _layers;
                };
            }
        }
    }
}
#endif //!__SGL_CORE_GRAPHICS_VULKAN_INSTANCE_LAYER__