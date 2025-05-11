#ifndef __SGL_CORE_EVENT_DISPATCHER__
#define __SGL_CORE_EVENT_DISPATCHER__

#include "sgl/core/event/event.h"
#include "sgl/core/event/callbacks.h"

namespace sgl
{
	template<class E>
	class sglEventDispatcher
	{
	public:
		sglEventDispatcher(sglEvent<E>& event)
			:_event(event)
		{}
		~sglEventDispatcher() = default;
		template<class T>
		bool dispatch(sglEventProc<T> proc)
		{
			if constexpr (E::get_type() == T::get_type())
			{
				if (proc(static_cast<T&>(this->_event)))
				{
					this->_event.add_handled_times();
					return true;
				}
			}
			return false;
		}
		template<class ... T>
		bool dispatch(const sglEventProcs_T<T...>& procs)
		{
			return this->_dispatch(procs,std::make_index_sequence<sizeof...(T)>());
		}
		template<class ... T>
		bool dispatch(const sglEventCallbacks<T...>& callbacks)
		{
			return this->dispatch(callbacks.get());
		}
	private:
		template<class T,size_t...I>
		bool _dispatch(T& procs, std::index_sequence<I...>)
		{
			bool ret = false;
			((std::get<I>(procs) ? (ret |= this->dispatch(std::get<I>(procs))) : (false)), ...);
			return ret;
		}

	private:
		sglEvent<E>& _event;
	};
}


#endif //!__SGL_CORE_EVENT_DISPATCHER__