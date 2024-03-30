#include <vulkan/vulkan.h>
#include "sgl/core/graphics/vulkan/instance_extension.h"

namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkInstanceExtensions_Impl
                {
                    VkExtensionProperties * properties;
                    sglInt count;
                };
                
                const sglVkInstanceExtensions & sglVkInstanceExtensions::operator =(const sglVkInstanceExtensions & extensions)
                {
                    if(this->_extensions->count != extensions._extensions->count)
                    {
                        this->_extensions->count = extensions._extensions->count;
                        delete [] this->_extensions->properties;
                        this->_extensions->properties = new VkExtensionProperties[this->_extensions->count];
                    }
                    for(sglInt index = 0;index < this->_extensions->count;index++)this->_extensions->properties[index] = extensions._extensions->properties[index];
                    return *this;
                }
                sglVkInstanceExtensions::sglVkInstanceExtensions(const sglVkInstanceExtensions & extensions)
                    :_extensions(new sglVkInstanceExtensions_Impl)
                {
                    this->_extensions->count = extensions._extensions->count;
                    this->_extensions->properties = new VkExtensionProperties[this->_extensions->count];
                    for(sglInt index = 0;index < this->_extensions->count;index++)this->_extensions->properties[index] = extensions._extensions->properties[index];
                }
                sglVkInstanceExtensions::sglVkInstanceExtensions()
                    :_extensions(new sglVkInstanceExtensions_Impl)
                {
                    uint32_t _count_;
                    VkResult result;
                    result = vkEnumerateInstanceExtensionProperties(nullptr,&_count_,nullptr);
                    if(VK_SUCCESS != result)throw sglException("vkEnumerateInstanceExtensionProperties failed!",result);
                    this->_extensions->count = _count_;
                    this->_extensions->properties = new VkExtensionProperties[_count_];
                    vkEnumerateInstanceExtensionProperties(nullptr,&_count_,this->_extensions->properties);
                    if(VK_SUCCESS != result)throw sglException("vkEnumerateInstanceExtensionProperties failed!",result);
                }
                sglVkInstanceExtensions::~sglVkInstanceExtensions()
                {
                    delete [] this->_extensions->properties;
                    delete this->_extensions;
                    this->_extensions = nullptr;
                }
                sglInt sglVkInstanceExtensions::count()const
                {
                    return this->_extensions->count;
                }
                sglBool sglVkInstanceExtensions::existent(const sglChar * name)const
                {
                    for(sglInt index = 0;index < this->_extensions->count;index++)
                    {
                        const sglChar * src = name;
                        const sglChar * dst = &this->_extensions->properties[index].extensionName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            return true;
                        }
                    }
                    return false;
                }
                sglInt sglVkInstanceExtensions::find(const sglChar * name)const
                {
                    for(sglInt index = 0;index < this->_extensions->count;index++)
                    {
                        const sglChar * src = name;
                        const sglChar * dst = &this->_extensions->properties[index].extensionName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            return index;
                        }
                    }
                    return ~0;
                }
                sglVkInstanceExtension sglVkInstanceExtensions::at(sglInt index)const
                {
                    sglVkInstanceExtension ext;
                    ext.name = &this->_extensions->properties[index].extensionName[0];
                    ext.version_major = VK_VERSION_MAJOR(this->_extensions->properties[index].specVersion);
                    ext.version_minor = VK_VERSION_MINOR(this->_extensions->properties[index].specVersion);
                    ext.version_patch = VK_VERSION_PATCH(this->_extensions->properties[index].specVersion);
                    return ext;
                }
                sglVkInstanceExtension sglVkInstanceExtensions::at(const sglChar * name)const
                {
                    sglInt index = this->find(name);
                    sglVkInstanceExtension ext;
                    ext.name = &this->_extensions->properties[index].extensionName[0];
                    ext.version_major = VK_VERSION_MAJOR(this->_extensions->properties[index].specVersion);
                    ext.version_minor = VK_VERSION_MINOR(this->_extensions->properties[index].specVersion);
                    ext.version_patch = VK_VERSION_PATCH(this->_extensions->properties[index].specVersion);
                    return ext;
                }
                sglVkInstanceExtension sglVkInstanceExtensions::operator [](sglInt index)const
                {
                    return this->at(index);
                }
                sglVkInstanceExtension sglVkInstanceExtensions::operator [](const sglChar * name)const
                {
                    return this->at(name);
                }

            }
        }
    }
}
