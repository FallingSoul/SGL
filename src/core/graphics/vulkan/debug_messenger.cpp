
#include <stdio.h>
#include <vulkan/vulkan.h>
#include "sgl/core/graphics/vulkan/debug_messenger.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkDebugMessenger_Impl
                {
                    VkDebugUtilsMessengerEXT messenger;
                    VkInstance instance;
                    PFN_vkCreateDebugUtilsMessengerEXT create_proc;
                    PFN_vkDestroyDebugUtilsMessengerEXT destroy_proc;
                    struct sglUserPointer
                    {
                        sglVkDebugMessenger * messenger;
                        sglVoid * ptr;
                    }user_ptr;
                    static VkBool32 VKAPI_PTR messenger_callback(
                        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                        VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                        const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData,
                        void * pUserData)
                    {
                        auto user_data = static_cast<sglUserPointer *>(pUserData);
                        sglVkDebugMessageSecurity security;
                        sglVkDebugMessageType type;
                        switch(messageSeverity)
                        {
                        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
                            security = sglVkDebugMessageSecurity::Verbose;
                            break;
                        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
                            security = sglVkDebugMessageSecurity::Info;
                            break;
                        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
                            security = sglVkDebugMessageSecurity::Warning;
                            break;
                        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
                            security = sglVkDebugMessageSecurity::Error;
                            break;
                        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT:
                            break;
                        }
                        switch(messageTypes)
                        {
                        case VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
                            type = sglVkDebugMessageType::General;
                            break;
                        case VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
                            type = sglVkDebugMessageType::Validation;
                            break;
                        case VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
                            type = sglVkDebugMessageType::Performance;
                            break;
                        }
                        return user_data->messenger->messenger_callback(pCallbackData->pMessage,security,type,user_data->ptr);
                    }
                    static sglVoid populate(VkDebugUtilsMessengerCreateInfoEXT & info)
                    {
                        info = {};
                        info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                        info.messageSeverity =
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                        info.messageType = 
                            VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
                        info.pfnUserCallback = messenger_callback;
                    }
                };
                sglVkDebugMessenger::sglVkDebugMessenger(const sglVkInstance & instance)
                    :_messenger(new sglVkDebugMessenger_Impl)
                {
                    this->_messenger->user_ptr.messenger = this;
                    this->_messenger->user_ptr.ptr = nullptr;
                    VkDebugUtilsMessengerCreateInfoEXT info{};
                    sglVkDebugMessenger_Impl::populate(info);
                    info.pUserData = &this->_messenger->user_ptr;
                    this->_messenger->instance = reinterpret_cast<VkInstance>(instance.get_handle());
                    this->_messenger->create_proc = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(instance.get_proc("vkCreateDebugUtilsMessengerEXT"));
                    this->_messenger->destroy_proc = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(instance.get_proc("vkDestroyDebugUtilsMessengerEXT"));
                    
                    if(nullptr == this->_messenger->create_proc)
                    {
                        throw sglException("Cannot get vkCreateDebugUtilsMessengerEXT address from vulkan instance!");
                    }
                    if(nullptr == this->_messenger->destroy_proc)
                    {
                        throw sglException("Cannot get vkDestroyDebugUtilsMessengerEXT address from vulkan instance!");
                    }
                    if(VK_SUCCESS != this->_messenger->create_proc(this->_messenger->instance,&info,nullptr,&this->_messenger->messenger))
                    {
                        throw sglException("Cannot create vulkan debug messenger!");
                    }
                }
                sglVkDebugMessenger::~sglVkDebugMessenger()
                {
                    this->_messenger->destroy_proc(this->_messenger->instance,this->_messenger->messenger,nullptr);
                    delete this->_messenger;
                    this->_messenger = nullptr;
                }
                sglBool sglVkDebugMessenger::messenger_callback(const sglChar * message,sglVkDebugMessageSecurity security,sglVkDebugMessageType type,sglVoid * user_ptr)
                {
                    puts(message);
                    return VK_FALSE;
                }
            }
        }
    }
}