#ifndef __SGL_CORE_GRAPHICS_VULKAN_DEBUG_MESSENGER__
#define __SGL_CORE_GRAPHICS_VULKAN_DEBUG_MESSENGER__



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
                enum class sglVkDebugMessageSecurity
                {
                    Verbose,
                    Info,
                    Warning,
                    Error
                };
                enum class sglVkDebugMessageType
                {
                    General,
                    Validation,
                    Performance
                };
                class SGL_API sglVkDebugMessenger
                {
                public:
                    sglVkDebugMessenger(const sglVkDebugMessenger&) = delete;
                    const sglVkDebugMessenger & operator =(const sglVkDebugMessenger&) = delete;

                    sglVkDebugMessenger(const sglVkInstance & instance);
                    ~sglVkDebugMessenger();
                    virtual sglBool messenger_callback(const sglChar * message,sglVkDebugMessageSecurity security,sglVkDebugMessageType type,sglVoid * user_ptr);
                private:
                    struct sglVkDebugMessenger_Impl * _messenger;
                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_VULKAN_DEBUG_MESSENGER__