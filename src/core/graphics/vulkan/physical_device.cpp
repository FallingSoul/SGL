#include <vulkan/vulkan.h>
#include "sgl/core/graphics/vulkan/physical_device.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkPhysicalDevice_Impl
                {
                    sglInt count;
                    VkInstance instance;
                    VkPhysicalDevice * devices;
                    VkPhysicalDevice * device;
                    VkPhysicalDeviceProperties properties;
                    VkPhysicalDeviceFeatures features;
                    sglVoid enumerate()
                    {
                        uint32_t _count_ = 0;
                        VkResult result;
                        result = vkEnumeratePhysicalDevices(this->instance,&_count_,nullptr);
                        if(VK_SUCCESS != result)
                        {
                            throw sglException("Cannot enumerate vulkan physical devices!");
                        }
                        this->count = _count_;
                        this->devices = new VkPhysicalDevice[this->count];
                        result = vkEnumeratePhysicalDevices(this->instance,&_count_,this->devices);
                        if(VK_SUCCESS != result)
                        {
                            throw sglException("Cannot enumerate vulkan physical devices!");
                        }
                    }
                    sglVoid value()
                    {
                        if(this->device)
                        {
                            vkGetPhysicalDeviceProperties(*this->device,&this->properties);
                            vkGetPhysicalDeviceFeatures(*this->device,&this->features);
                        }
                        else
                        {
                            this->properties = {};
                            this->features = {};
                        }
                    }
                };
                sglVkPhysicalDevice::sglVkPhysicalDevice(const sglVkInstance & instance)
                    :_device(new sglVkPhysicalDevice_Impl)
                {
                    this->_device->device = nullptr;
                    this->_device->properties = {};
                    this->_device->instance = reinterpret_cast<VkInstance>(instance.get_handle());
                    this->_device->enumerate();
                    this->_device->value();
                }
                sglVkPhysicalDevice::sglVkPhysicalDevice(const sglVkInstance & instance,const sglChar * name)
                    :_device(new sglVkPhysicalDevice_Impl)
                {
                    this->_device->device = nullptr;
                    this->_device->properties = {};
                    this->_device->instance = reinterpret_cast<VkInstance>(instance.get_handle());
                    this->_device->enumerate();
                    for(sglInt index = 0;index < this->_device->count;index++)
                    {
                        VkPhysicalDeviceProperties properties;
                        vkGetPhysicalDeviceProperties(this->_device->devices[index],&properties);
                        const sglChar * src = name;
                        const sglChar * dst = &properties.deviceName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            this->_device->device = &this->_device->devices[index];
                            this->_device->value();
                            break;
                        }
                    }
                }
                sglVkPhysicalDevice::sglVkPhysicalDevice(const sglVkInstance & instance,sglInt index)
                    :_device(new sglVkPhysicalDevice_Impl)
                {
                    this->_device->device = nullptr;
                    this->_device->properties = {};
                    this->_device->instance = reinterpret_cast<VkInstance>(instance.get_handle());
                    this->_device->enumerate();
                    if(index >= this->_device->count)
                    {
                        throw sglException("Out of range!");
                    }
                    this->_device->device = &this->_device->devices[index];
                    this->_device->value();
                }
                sglVkPhysicalDevice::sglVkPhysicalDevice(const sglVkPhysicalDevice & device)
                    :_device(new sglVkPhysicalDevice_Impl)
                {
                    this->_device->device = nullptr;
                    this->_device->properties = {};
                    this->_device->instance = device._device->instance;
                    this->_device->count = device._device->count;
                    this->_device->devices = new VkPhysicalDevice[this->_device->count];
                    for(sglInt index = 0;index < this->_device->count;index++)
                    {
                        this->_device->devices[index] = device._device->devices[index];
                    }
                    this->_device->device = &this->_device->devices[device.index()];
                    this->_device->properties = device._device->properties;
                    this->_device->features = device._device->features;
                }
                sglVkPhysicalDevice::~sglVkPhysicalDevice()
                {
                    delete [] this->_device->devices;
                    delete this->_device;
                    this->_device = nullptr;
                }

                sglBool sglVkPhysicalDevice::invalid()const
                {
                    return nullptr == this->_device->device;
                }
                sglBool sglVkPhysicalDevice::valid()const
                {
                    return nullptr != this->_device->device;
                }
                sglVkPhysicalDevice sglVkPhysicalDevice::next()const
                {
                    sglVkPhysicalDevice device = *this;
                    return ++device;
                }
                sglInt sglVkPhysicalDevice::index()const
                {
                    return (this->_device->device - this->_device->devices);
                }
                sglBool sglVkPhysicalDevice::operator == (const sglVkPhysicalDevice & device)
                {
                    return this->_device->device == device._device->device || *this->_device->device == *device._device->device;
                }
                const sglVkPhysicalDevice & sglVkPhysicalDevice::operator = (const sglVkPhysicalDevice & device)
                {
                    delete [] this->_device->devices;
                    this->_device->instance = device._device->instance;
                    this->_device->count = device._device->count;
                    this->_device->devices = new VkPhysicalDevice [this->_device->count];
                    for(sglInt index = 0;index < this->_device->count;index++)
                    {
                        this->_device->devices[index] = device._device->devices[index];
                    }
                    this->_device->device = &this->_device->devices[device.index()];
                    this->_device->properties = device._device->properties;
                    this->_device->features = device._device->features;
                    
                    return *this;
                }
                const sglVkPhysicalDevice & sglVkPhysicalDevice::operator ++()
                {
                    if(this->_device->device)
                    {
                        ++this->_device->device;
                        if(this->index() >= this->count())
                        {
                            this->_device->device = nullptr;
                            this->_device->properties = {};
                        }
                    }
                    else
                    {
                        this->_device->device = &this->_device->devices[0];
                    }
                    if(this->_device->device)
                    {
                        this->_device->value();
                    }
                    return *this;
                }
                sglInt sglVkPhysicalDevice::count()
                {
                    return this->_device->count;
                }
                sglConfigInfo sglVkPhysicalDevice::get_config_driver()const
                {
                    sglConfigInfo config{};
                    if(nullptr == this->_device->device)return config;
                    config.name = &this->_device->properties.deviceName[0];
                    config.version_major = VK_VERSION_MAJOR(this->_device->properties.driverVersion);
                    config.version_minor = VK_VERSION_MINOR(this->_device->properties.driverVersion);
                    config.version_patch = VK_VERSION_PATCH(this->_device->properties.driverVersion);
                    return config;
                }
                sglConfigInfo sglVkPhysicalDevice::get_config_api()const
                {
                    sglConfigInfo config{};
                    if(nullptr == this->_device->device)return config;
                    config.name = &this->_device->properties.deviceName[0];
                    config.version_major = VK_VERSION_MAJOR(this->_device->properties.apiVersion);
                    config.version_minor = VK_VERSION_MINOR(this->_device->properties.apiVersion);
                    config.version_patch = VK_VERSION_PATCH(this->_device->properties.apiVersion);
                    return config;
                }
                sglVkPhysicalDeviceType sglVkPhysicalDevice::get_type()const
                {
                    if(this->_device->device)
                        switch(this->_device->properties.deviceType)
                        {
                        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
                            return sglVkPhysicalDeviceType::Other;
                        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
                            return sglVkPhysicalDeviceType::Integrated;
                        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
                            return sglVkPhysicalDeviceType::Discrete;
                        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
                            return sglVkPhysicalDeviceType::Virtual;
                        case VK_PHYSICAL_DEVICE_TYPE_CPU:
                            return sglVkPhysicalDeviceType::CPU;
                        case VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM:
                            break;
                        }
                    return sglVkPhysicalDeviceType::Unknown;
                }
            }
        }
    }
}
