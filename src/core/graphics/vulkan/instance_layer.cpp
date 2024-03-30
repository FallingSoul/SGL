#include <vulkan/vulkan.h>
#include "sgl/core/graphics/vulkan/instance_layer.h"

namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace vulkan
            {
                struct sglVkInstanceLayers_Impl
                {
                    sglInt count;
                    VkLayerProperties * properties;
                };
                
                const sglVkInstanceLayers & sglVkInstanceLayers::operator =(const sglVkInstanceLayers & layers)
                {
                    if(this->_layers->count != layers._layers->count)
                    {
                        this->_layers->count = layers._layers->count;
                        delete [] this->_layers->properties;
                        this->_layers->properties = new VkLayerProperties[this->_layers->count];
                    }
                    for(sglInt index = 0;index < this->_layers->count;index++)this->_layers->properties[index] = layers._layers->properties[index];
                    return *this;
                }
                sglVkInstanceLayers::sglVkInstanceLayers(const sglVkInstanceLayers & layers)
                    :_layers(new sglVkInstanceLayers_Impl)
                {
                    this->_layers->count = layers._layers->count;
                    this->_layers->properties = new VkLayerProperties[this->_layers->count];
                    for(sglInt index = 0;index < this->_layers->count;index++)this->_layers->properties[index] = layers._layers->properties[index];
                }
                sglVkInstanceLayers::sglVkInstanceLayers()
                    :_layers(new sglVkInstanceLayers_Impl)
                {
                    uint32_t _count_;
                    VkResult result;
                    result = vkEnumerateInstanceLayerProperties(&_count_,nullptr);
                    if(VK_SUCCESS != result)throw sglException("vkEnumerateInstanceLayerProperties failed!",result);
                    this->_layers->count = _count_;
                    this->_layers->properties = new VkLayerProperties[_count_];
                    result = vkEnumerateInstanceLayerProperties(&_count_,this->_layers->properties);
                    if(VK_SUCCESS != result)throw sglException("vkEnumerateInstanceLayerProperties failed!",result);
                }
                sglVkInstanceLayers::~sglVkInstanceLayers()
                {
                    delete [] this->_layers->properties;
                    delete this->_layers;
                    this->_layers = nullptr;
                }
                sglBool sglVkInstanceLayers::existent(const sglChar * name)const
                {
                    for(sglInt index = 0;index < this->_layers->count;index++)
                    {
                        const sglChar * src = name;
                        const sglChar * dst = &this->_layers->properties[index].layerName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            return true;
                        }
                    }
                    return false;
                }
                sglInt sglVkInstanceLayers::find(const sglChar * name)const
                {
                    for(sglInt index = 0;index < this->_layers->count;index++)
                    {
                        const sglChar * src = name;
                        const sglChar * dst = &this->_layers->properties[index].layerName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            return index;
                        }
                    }
                    return ~0;
                }
                sglInt sglVkInstanceLayers::count()const
                {
                    return this->_layers->count;
                }
                sglVkInstanceLayer sglVkInstanceLayers::at(sglInt index)const
                {
                    sglVkInstanceLayer layer;
                    layer.name = &this->_layers->properties[index].layerName[0];
                    layer.description = &this->_layers->properties[index].description[0];
                    layer.version_major = VK_VERSION_MAJOR(this->_layers->properties[index].specVersion);
                    layer.version_minor = VK_VERSION_MINOR(this->_layers->properties[index].specVersion);
                    layer.version_patch = VK_VERSION_PATCH(this->_layers->properties[index].specVersion);
                    
                    layer.implementation_version_major = VK_VERSION_MAJOR(this->_layers->properties[index].implementationVersion);
                    layer.implementation_version_minor = VK_VERSION_MINOR(this->_layers->properties[index].implementationVersion);
                    layer.implementation_version_patch = VK_VERSION_PATCH(this->_layers->properties[index].implementationVersion);
                    return layer;
                }
                sglVkInstanceLayer sglVkInstanceLayers::at(const sglChar * name)const
                {
                    sglInt index = this->find(name);

                    sglVkInstanceLayer layer;
                    layer.name = &this->_layers->properties[index].layerName[0];
                    layer.description = &this->_layers->properties[index].description[0];
                    layer.version_major = VK_VERSION_MAJOR(this->_layers->properties[index].specVersion);
                    layer.version_minor = VK_VERSION_MINOR(this->_layers->properties[index].specVersion);
                    layer.version_patch = VK_VERSION_PATCH(this->_layers->properties[index].specVersion);
                    
                    layer.implementation_version_major = VK_VERSION_MAJOR(this->_layers->properties[index].implementationVersion);
                    layer.implementation_version_minor = VK_VERSION_MINOR(this->_layers->properties[index].implementationVersion);
                    layer.implementation_version_patch = VK_VERSION_PATCH(this->_layers->properties[index].implementationVersion);
                    return layer;
                }
                sglVkInstanceLayer sglVkInstanceLayers::operator [](sglInt index)const
                {
                    return this->at(index);
                }
                sglVkInstanceLayer sglVkInstanceLayers::operator [](const sglChar * name)const
                {
                    return this->at(name);
                }
            }
        }
    }
}