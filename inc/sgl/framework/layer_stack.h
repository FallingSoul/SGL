#ifndef __SGL_FRAMEWORK_LAYER_STACK__
#define __SGL_FRAMEWORK_LAYER_STACK__


#include "sgl/core/layer.h"

namespace sgl
{
	class SGL_API sglLayerStack
	{
		using iterator = std::vector<sglLayer*>::iterator;
	public:
		sglLayerStack();
		sglLayerStack(size_t size);
		~sglLayerStack();
		
		void clear();
		void extend(size_t size);
		void push_overlay(sglLayer* layer);
		void push(sglLayer* layer);
		sglLayer* pop();
		iterator begin();
		iterator end();
	private:
		std::unique_ptr<struct sglLayerStackInfo> _info;
	};
}


#endif //!__SGL_FRAMEWORK_LAYER_STACK__