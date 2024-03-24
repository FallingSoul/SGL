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
                struct sglVkInstanceExtension_Impl
                {
                    static struct sglVkInstanceExtensionGroup
                    {
                        VkExtensionProperties * extensions;
                        sglInt count;
                        ~sglVkInstanceExtensionGroup()
                        {
                            delete [] this->extensions;
                            this->extensions = nullptr;
                            this->count = 0;
                        }
                        sglVkInstanceExtensionGroup()
                            :extensions(nullptr),count(0)
                        {
                            uint32_t _count_ = 0;
                            VkResult result;
                            result = vkEnumerateInstanceExtensionProperties(nullptr,&_count_,nullptr);
                            if(VK_SUCCESS != result)
                            {
                                throw sglException("Cannot enumrate vulkan extension properties!");
                            }
                            this->count = _count_;
                            this->extensions = new VkExtensionProperties[this->count];
                            result = vkEnumerateInstanceExtensionProperties(nullptr,&_count_,this->extensions);
                            if(VK_SUCCESS != result)
                            {
                                throw sglException("Cannot enumrate vulkan extension properties!");
                            }
                        }
                    }group;
                    VkExtensionProperties * extension;
                };
                sglVkInstanceExtension_Impl::sglVkInstanceExtensionGroup sglVkInstanceExtension_Impl::group{};


                sglInt sglVkInstanceExtension::count()
                {
                    return sglVkInstanceExtension_Impl::group.count;
                }
                sglVkInstanceExtension::sglVkInstanceExtension(const sglChar * name)
                    :_extension(new sglVkInstanceExtension_Impl)
                {
                    this->_extension->extension = nullptr;
                    for(sglInt index = 0;index < this->_extension->group.count;index++)
                    {
                        const sglChar * src = name;
                        const sglChar * dst = &this->_extension->group.extensions[index].extensionName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            this->_extension->extension = &this->_extension->group.extensions[index];
                            break;
                        }
                    }
                }
                sglVkInstanceExtension::sglVkInstanceExtension(sglInt index)
                    :_extension(new sglVkInstanceExtension_Impl)
                {
                    this->_extension->extension = nullptr;
                    if(index >= sglVkInstanceExtension_Impl::group.count)
                    {
                        throw sglException("Out of range!");
                    }
                    this->_extension->extension = &sglVkInstanceExtension_Impl::group.extensions[index];
                }
                sglVkInstanceExtension::sglVkInstanceExtension()
                    :_extension(new sglVkInstanceExtension_Impl)
                {
                    this->_extension->extension = nullptr;
                }
                sglVkInstanceExtension::sglVkInstanceExtension(const sglVkInstanceExtension & ext)
                    :_extension(new sglVkInstanceExtension_Impl)
                {
                    this->_extension->extension = ext._extension->extension;
                }
                sglVkInstanceExtension::~sglVkInstanceExtension()
                {
                    delete this->_extension;
                    this->_extension = nullptr;
                }
                    
                sglBool sglVkInstanceExtension::operator ==(const sglVkInstanceExtension & ext)const
                {
                    return ext._extension->extension != this->_extension->extension;
                }
                const sglVkInstanceExtension & sglVkInstanceExtension::operator =(const sglVkInstanceExtension & ext)
                {
                    this->_extension->extension = ext._extension->extension;
                    return *this;
                }
                const sglVkInstanceExtension & sglVkInstanceExtension::operator ++()
                {
                    return *this = this->next();
                }
                sglConfigInfo sglVkInstanceExtension::get_config()const
                {
                    sglConfigInfo config{};
                    if(nullptr == this->_extension)return config;
                    config.name = this->_extension->extension->extensionName;
                    config.version_major = VK_VERSION_MAJOR(this->_extension->extension->specVersion);
                    config.version_minor = VK_VERSION_MINOR(this->_extension->extension->specVersion);
                    config.version_patch = VK_VERSION_PATCH(this->_extension->extension->specVersion);
                    return config;
                }
                sglBool sglVkInstanceExtension::valid()const
                {
                    return nullptr != this->_extension->extension;
                }
                sglBool sglVkInstanceExtension::invalid()const
                {
                    return nullptr == this->_extension->extension;
                }
                sglInt sglVkInstanceExtension::index()const
                {
                    return (this->_extension->extension - &sglVkInstanceExtension_Impl::group.extensions[0]);
                }
                sglVkInstanceExtension sglVkInstanceExtension::next()const
                {
                    sglVkInstanceExtension ext = *this;
                    if(ext._extension->extension)
                    {
                        ++ext._extension->extension;
                        if(ext.index() >= this->count())
                        {
                            ext._extension->extension = nullptr;
                        }
                    }
                    else ext._extension->extension = &sglVkInstanceExtension_Impl::group.extensions[0];
                    return ext;
                }

            }
        }
    }
}
