#include "sgl/framework/layer_stack.h"


namespace sgl
{
	struct sglLayerStackInfo
	{
		std::vector<sglLayer*> layers;
		size_t index = 0;
	};
	sglLayerStack::sglLayerStack() 
		:_info(std::make_unique<sglLayerStackInfo>())
	{}
	sglLayerStack::sglLayerStack(size_t size)
		:_info(std::make_unique<sglLayerStackInfo>())
	{
		this->_info->layers.resize(size);
	}
	sglLayerStack::~sglLayerStack()
	{
		while (this->_info->index > 0)
		{
			this->_info->index--;
			this->_info->layers[this->_info->index]->on_detach();
			this->_info->layers[this->_info->index] = nullptr;
		}
	}


	void sglLayerStack::extend(size_t size)
	{
		this->_info->layers.resize(this->_info->layers.size() + size);
		
	}
	void sglLayerStack::push_overlay(sglLayer* layer)
	{
		this->_info->layers.emplace(this->_info->layers.begin(), layer);
		this->_info->index++;
		layer->on_attach();
	}
	void sglLayerStack::push(sglLayer* layer)
	{
		if (this->_info->index == this->_info->layers.size())
		{
			this->_info->layers.emplace_back(layer);
		}
		else
		{
			this->_info->layers[this->_info->index] = layer;
		}
		this->_info->index++;
		layer->on_attach();
	}
	sglLayer* sglLayerStack::pop()
	{
		if (!this->_info->index)return nullptr;
		this->_info->index--;
		this->_info->layers[this->_info->index]->on_detach();
		return this->_info->layers[this->_info->index];
	}

	void sglLayerStack::clear()
	{
		while (this->_info->index > 0)
		{
			this->_info->index--;
			this->_info->layers[this->_info->index]->on_detach();
			this->_info->layers[this->_info->index] = nullptr;
		}
		this->_info->layers.clear();
	}
	sglLayerStack::iterator sglLayerStack::begin() 
	{
		return this->_info->layers.begin();
	}
	sglLayerStack::iterator sglLayerStack::end() 
	{
		return this->_info->layers.begin() + this->_info->index;
	}
}