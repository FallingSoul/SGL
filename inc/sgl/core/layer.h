#ifndef __SGL_CORE_LAYER__
#define __SGL_CORE_LAYER__

#include "sgl/core/event/dispatcher.h"
#include "sgl/core/time.h"

namespace sgl
{
	class SGL_API sglLayer
	{
	public:
		using sglLayerTime = sglTime;
	public:
		sglLayer(const char* name)
			:_name(name)
		{}
		virtual ~sglLayer() {}
		virtual sglAllEventCallbacks get_callbacks() {static sglNoneEventCallbacks none;return none;}
		const char* get_name()const { return this->_name; }
	public:
		virtual void on_attach() {}
		virtual void on_detach() {}
		virtual void on_update(sglLayerTime delta_time) {}
	public:
		template<class E>
		bool on_event(E& e)
		{
			sglEventDispatcher dispatcher(e);
			auto callbacks = this->get_callbacks();
			return dispatcher.dispatch(callbacks);
		}
	private:
		const char* _name;
	};
}

#endif //!__SGL_CORE_LAYER__