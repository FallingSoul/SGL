#include <vulkan/vulkan.h>
#include "sgl/core/graphics/vulkan/instance.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkInstance_Impl
                {
                    VkInstance instance;
                };
                sglVkInstance::sglVkInstance(const sglConfigInfo & app,const sglChar ** extensions,sglInt ext_count)
                    :_instance(new sglVkInstance_Impl)
                {
                    sglConfigInfo sgl_info = sglGetConfigInfo();
                    uint32_t _count_ = ext_count;
                    const char ** ext = extensions;
                    for(sglInt index = 0;index < ext_count;index++)
                    {
                        sglVkInstanceExtension check = extensions[index];
                        if(check.invalid())
                        {
                            throw sglException("Unsupported vulkan instance extension!");
                        }
                    }
                    
                    VkApplicationInfo app_info
                    {
                        VK_STRUCTURE_TYPE_APPLICATION_INFO,
                        nullptr,
                        app.name,
                        VK_MAKE_VERSION(app.version_major,app.version_minor,app.version_patch),
                        sgl_info.name,
                        VK_MAKE_VERSION(sgl_info.version_major,sgl_info.version_minor,sgl_info.version_patch),
                        VK_API_VERSION_1_0
                    };
                    VkInstanceCreateInfo create = 
                    {
                        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                        nullptr,
                        0,
                        &app_info,
                        0,nullptr,
                        _count_,ext
                    };
                    VkResult result = vkCreateInstance(&create,nullptr,&this->_instance->instance);
                    
                    if(VK_SUCCESS != result)
                    {
                        throw sglException("Cannot create vulkan instance!");
                    }
                }
                sglVkInstance::sglVkInstance(const sglConfigInfo & app,const sglVkInstanceExtension * extensions,sglInt ext_count,const sglVkInstanceLayer & layer)
                    :_instance(new sglVkInstance_Impl)
                {
                    sglConfigInfo sgl_info = sglGetConfigInfo();
                    uint32_t _count_ = ext_count;
                    const char ** ext = nullptr;
                    if(sglVkInstanceExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME).invalid())
                    {
                        ext = new const char * [ext_count];
                    }
                    else
                    {
                        ++_count_;
                        ext = new const char * [ext_count + 1];
                        ext[ext_count] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
                    }
                    const char * lay = layer.get_config().name;
                    for(sglInt index = 0;index < ext_count;index++)ext[index] = extensions[index].get_config().name;
                    VkApplicationInfo app_info
                    {
                        VK_STRUCTURE_TYPE_APPLICATION_INFO,
                        nullptr,
                        app.name,
                        VK_MAKE_VERSION(app.version_major,app.version_minor,app.version_patch),
                        sgl_info.name,
                        VK_MAKE_VERSION(sgl_info.version_major,sgl_info.version_minor,sgl_info.version_patch),
                        VK_API_VERSION_1_0
                    };
                    VkInstanceCreateInfo create = 
                    {
                        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                        nullptr,
                        0,
                        &app_info,
                        1,&lay,
                        _count_,ext
                    };
                    VkResult result = vkCreateInstance(&create,nullptr,&this->_instance->instance);
                    delete [] ext;
                    if(VK_SUCCESS != result)
                    {
                        throw sglException("Cannot create vulkan instance!");
                    }
                }
                sglVkInstance::sglVkInstance(const sglConfigInfo & app,const sglVkInstanceExtension * extensions,sglInt ext_count)
                    :_instance(new sglVkInstance_Impl)
                {
                    sglConfigInfo sgl_info = sglGetConfigInfo();
                    uint32_t _count_ = ext_count;
                    const char ** ext = new const char * [ext_count];
                    for(sglInt index = 0;index < ext_count;index++)ext[index] = extensions[index].get_config().name;
                    VkApplicationInfo app_info
                    {
                        VK_STRUCTURE_TYPE_APPLICATION_INFO,
                        nullptr,
                        app.name,
                        VK_MAKE_VERSION(app.version_major,app.version_minor,app.version_patch),
                        sgl_info.name,
                        VK_MAKE_VERSION(sgl_info.version_major,sgl_info.version_minor,sgl_info.version_patch),
                        VK_API_VERSION_1_0
                    };
                    VkInstanceCreateInfo create = 
                    {
                        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                        nullptr,
                        0,
                        &app_info,
                        0,nullptr,
                        _count_,ext
                    };
                    VkResult result = vkCreateInstance(&create,nullptr,&this->_instance->instance);
                    delete [] ext;
                    if(VK_SUCCESS != result)
                    {
                        throw sglException("Cannot create vulkan instance!");
                    }
                }
                sglVkInstance::sglVkInstance(const sglConfigInfo & app,const sglChar ** extensions,sglInt ext_count,const sglChar * layer)
                {
                    sglConfigInfo sgl_info = sglGetConfigInfo();
                    uint32_t _count_ = ext_count;
                    const char ** ext = nullptr;
                    if(sglVkInstanceExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME).invalid())
                    {
                        ext = new const char * [ext_count];
                    }
                    else
                    {
                        ++_count_;
                        ext = new const char * [ext_count + 1];
                        ext[ext_count] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
                    }
                    const char * lay = layer;
                    for(sglInt index = 0;index < ext_count;index++)
                    {
                        sglVkInstanceExtension check = ext[index] = extensions[index];
                        if(check.invalid())
                        {
                            throw sglException("Unsupported vulkan instance extension!");
                        }
                    }
                    
                    VkApplicationInfo app_info
                    {
                        VK_STRUCTURE_TYPE_APPLICATION_INFO,
                        nullptr,
                        app.name,
                        VK_MAKE_VERSION(app.version_major,app.version_minor,app.version_patch),
                        sgl_info.name,
                        VK_MAKE_VERSION(sgl_info.version_major,sgl_info.version_minor,sgl_info.version_patch),
                        VK_API_VERSION_1_0
                    };
                    VkInstanceCreateInfo create = 
                    {
                        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                        nullptr,
                        0,
                        &app_info,
                        1,&lay,
                        _count_,ext
                    };
                    VkResult result = vkCreateInstance(&create,nullptr,&this->_instance->instance);
                    delete [] ext;
                    if(VK_SUCCESS != result)
                    {
                        throw sglException("Cannot create vulkan instance!");
                    }
                }
                sglVkInstance::~sglVkInstance()
                {
                    vkDestroyInstance(this->_instance->instance,nullptr);
                    delete this->_instance;
                    this->_instance = nullptr;
                }
                auto sglVkInstance::get_proc(const sglChar * name)const -> sglVoid (*)()
                {
                    return static_cast<sglVoid (*)()>(vkGetInstanceProcAddr(this->_instance->instance,name));
                }
                sglVoid * sglVkInstance::get_handle()const
                {
                    return this->_instance->instance;
                }
            }
        }
    }
}
