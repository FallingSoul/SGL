#ifndef __SGL_CORE_GRAPHICS_VULKAN_INSTANCE__
#define __SGL_CORE_GRAPHICS_VULKAN_INSTANCE__

#include "sgl/core/family.h"

#include "sgl/core/graphics/vulkan/instance_layer.h"
#include "sgl/core/graphics/vulkan/instance_extension.h"

namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkApplicationInfo : public sglConfigInfo
                {
                };
                class SGL_API sglVkInstance
                {
                public:
                    sglVkInstance(const sglVkInstance&) = delete;
                    const sglVkInstance & operator =(const sglVkInstance &) = delete;
                    sglVkInstance(const sglVkApplicationInfo & app,const sglChar ** extensions,sglInt ext_count);
                    sglVkInstance(const sglVkApplicationInfo & app,const sglChar ** extensions,sglInt ext_count,const sglChar * layer);
                    ~sglVkInstance();
                    auto get_proc(const sglChar * name)const -> sglVoid (*)();
                    sglVoid * get_handle()const;
                private:
                    struct sglVkInstance_Impl * _instance;
                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_VULKAN_INSTANCE__