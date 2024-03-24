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
                struct sglVkInstanceLayer_Impl
                {
                    static struct sglVkInstanceLayerGroup
                    {
                        VkLayerProperties * layers;
                        sglInt count;
                        sglVkInstanceLayerGroup()
                            :layers(nullptr),count(0)
                        {
                            uint32_t _count_ = 0;
                            VkResult result;
                            result = vkEnumerateInstanceLayerProperties(&_count_,nullptr);
                            if(VK_SUCCESS != result)
                            {
                                throw sglException("Cannot enumerate vulkan layer properties!");
                            }
                            this->count = _count_;
                            this->layers = new VkLayerProperties[this->count];
                            result = vkEnumerateInstanceLayerProperties(&_count_,this->layers);
                            if(VK_SUCCESS != result)
                            {
                                throw sglException("Cannot enumerate vulkan layer properties!");
                            }
                        }
                        ~sglVkInstanceLayerGroup()
                        {
                            delete [] this->layers;
                            this->layers = nullptr;
                            this->count = 0;
                        }
                    }group;
                    VkLayerProperties * layer;
                };
                sglVkInstanceLayer_Impl::sglVkInstanceLayerGroup sglVkInstanceLayer_Impl::group;

                
                sglVkInstanceLayer::sglVkInstanceLayer()
                    :_layer(new sglVkInstanceLayer_Impl)
                {
                    this->_layer->layer = nullptr;
                }
                sglVkInstanceLayer::sglVkInstanceLayer(const sglChar * name)
                    :_layer(new sglVkInstanceLayer_Impl)
                {
                    this->_layer->layer = nullptr;
                    for(sglInt index = 0;index < sglVkInstanceLayer_Impl::group.count;index++)
                    {
                        const sglChar * src = name;
                        const sglChar * dst = &sglVkInstanceLayer_Impl::group.layers[index].layerName[0];
                        while(*src == *dst && *src && *dst)++src,++dst;
                        if(*src == *dst)
                        {
                            this->_layer->layer = &sglVkInstanceLayer_Impl::group.layers[index];
                            break;
                        }
                    }

                }
                sglVkInstanceLayer::sglVkInstanceLayer(sglInt index)
                    :_layer(new sglVkInstanceLayer_Impl)
                {
                    this->_layer->layer = nullptr;
                    if(index >= sglVkInstanceLayer_Impl::group.count)
                    {
                        throw sglException("Out of range!");
                    }
                    this->_layer->layer = &sglVkInstanceLayer_Impl::group.layers[index];
                }
                sglVkInstanceLayer::sglVkInstanceLayer(const sglVkInstanceLayer & layer)
                    :_layer(new sglVkInstanceLayer_Impl)
                {
                    this->_layer->layer = layer._layer->layer;
                }
                sglVkInstanceLayer::~sglVkInstanceLayer()
                {
                    delete this->_layer;
                    this->_layer = nullptr;
                }
                sglConfigInfo sglVkInstanceLayer::get_config()const
                {
                    sglConfigInfo config{};
                    if(nullptr == this->_layer->layer)return config;
                    config.name = &this->_layer->layer->layerName[0];
                    config.version_major = VK_VERSION_MAJOR(this->_layer->layer->specVersion);
                    config.version_minor = VK_VERSION_MINOR(this->_layer->layer->specVersion);
                    config.version_patch = VK_VERSION_PATCH(this->_layer->layer->specVersion);
                    return config;
                }
                sglConfigInfo sglVkInstanceLayer::get_config_impl()const
                {
                    sglConfigInfo config{};
                    if(nullptr == this->_layer->layer)return config;
                    config.name = &this->_layer->layer->layerName[0];
                    config.version_major = VK_VERSION_MAJOR(this->_layer->layer->implementationVersion);
                    config.version_minor = VK_VERSION_MINOR(this->_layer->layer->implementationVersion);
                    config.version_patch = VK_VERSION_PATCH(this->_layer->layer->implementationVersion);
                    return config;
                }
                const sglChar * sglVkInstanceLayer::get_description()const
                {
                    if(nullptr == this->_layer->layer)return nullptr;
                    return &this->_layer->layer->description[0];
                }
                sglBool sglVkInstanceLayer::valid()const
                {
                    return nullptr != this->_layer->layer;
                }
                sglBool sglVkInstanceLayer::invalid()const
                {
                    return nullptr == this->_layer->layer;
                }
                sglVkInstanceLayer sglVkInstanceLayer::next()const
                {
                    sglVkInstanceLayer layer = *this;
                    if(layer._layer->layer)
                    {
                        ++layer._layer->layer;
                        if(layer.index() >= this->count())
                        {
                            layer._layer->layer = nullptr;
                        }
                    }
                    else layer._layer->layer = &sglVkInstanceLayer_Impl::group.layers[0];
                    return layer;
                }
                sglInt sglVkInstanceLayer::index()const
                {
                    return (this->_layer->layer - sglVkInstanceLayer_Impl::group.layers);
                }
                sglBool sglVkInstanceLayer::operator ==(const sglVkInstanceLayer & layer)const
                {
                    return this->_layer->layer == layer._layer->layer;
                }
                const sglVkInstanceLayer & sglVkInstanceLayer::operator =(const sglVkInstanceLayer & layer)
                {
                    this->_layer->layer = layer._layer->layer;
                    return *this;
                }
                const sglVkInstanceLayer & sglVkInstanceLayer::operator ++()
                {
                    return *this = this->next();
                }
                sglInt sglVkInstanceLayer::count()
                {
                    return sglVkInstanceLayer_Impl::group.count;
                }
            }
        }
    }
}