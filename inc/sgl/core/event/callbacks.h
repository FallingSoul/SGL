#ifndef __SGL_CORE_EVENT_CALLBACKS__
#define __SGL_CORE_EVENT_CALLBACKS__


namespace sgl
{

	template<class T>
	using sglEventProc = std::function<bool(T&)>;;
	template<class ... E>
	using sglEventProcs_T = std::tuple<sglEventProc<E>...>;

	template<class T>
	class sglOnEventCallback
	{
	public:
		sglOnEventCallback(T* t)
			:_t(t)
		{ }
		~sglOnEventCallback() = default;
		template<class E>
		operator sglEventProc<E>()
		{
			return std::bind(&sglOnEventCallback<T>::on_event<E>, this, std::placeholders::_1);
		}
	public:
		template<class E>
		bool on_event(E& e)
		{
			if(this->_t)this->_t->on_event(e);
			return false;
		}
	private:
		T* _t;
	};


	template<class ... T>
	class sglEventCallbacks
	{
	public:
		using sglEventProcs = sglEventProcs_T<T...>;
	public:
		template<class ... E>
		sglEventCallbacks(const sglEventCallbacks<E...>& callbacks)
		{
			this->set_event_callbacks(callbacks.get());
		}
		template<class ... E>
		sglEventCallbacks(sglEventProc<E> ... callbacks)
		{
			this->set_event_callback(callbacks...);
		}
		sglEventCallbacks() = default;
		template<class E>
		void set_event_callback(sglEventProc<E> callback)
		{
			this->_set_event_callback(callback, std::make_index_sequence<std::tuple_size_v<sglEventProcs>>());
		}
		template<class ... E>
		void set_event_callbacks(const sglEventProcs_T<E...>& callbacks)
		{
			this->_set_event_callbacks(callbacks,std::make_index_sequence<std::tuple_size_v<std::decay_t<decltype(callbacks)>>>());
		}
		template<class ... E>
		void set_event_callbacks(sglEventProc<E> ... callbacks)
		{
			(this->set_event_callback(callbacks), ...);
		}
		template<class T>
		void set_on_event_callback(sglOnEventCallback<T>& callback)
		{
			this->_set_on_event_callback(callback, std::make_index_sequence<std::tuple_size_v<sglEventProcs>>());
		}
	public:
		const sglEventProcs& get()const
		{
			return this->_callbacks;
		}
		sglEventProcs& get()
		{
			return this->_callbacks;
		}
	private:
		template<class T,size_t ... I>
		void _set_on_event_callback(sglOnEventCallback<T>& callback, std::index_sequence<I...>)
		{
			((std::get<I>(this->_callbacks) = callback), ...);
		}
		template<class T, size_t ... I>
		void _set_event_callbacks(const T& callbacks, std::index_sequence<I...>)
		{
			((this->set_event_callback(std::get<I>(callbacks))), ...);
		}
		template<class E, size_t ... I>
		void _set_event_callback(sglEventProc<E> callback, std::index_sequence<I...>)
		{
			((std::is_same_v<std::decay_t<decltype(std::get<I>(this->_callbacks))>,
				std::decay_t<decltype(callback)>> ?
				(_assign(std::get<I>(this->_callbacks), callback), 0) : (0)), ...);
		}
		template<class L, class R>
		void _assign(L& l, R& r)
		{
			if constexpr (std::is_same_v<std::decay_t<L>, std::decay_t<R>>)
			{
				l = r;
			}
		}
	private:
		sglEventProcs _callbacks;
	};
	using sglNoneEventCallbacks = sglEventCallbacks<>;
	using sglAllEventCallbacks = sglEventCallbacks
	<
		event::sglWindowClose,
		event::sglWindowFocus,
		event::sglWindowMove,
		event::sglWindowResize,
		event::sglKeyPressed,
		event::sglKeyReleased,
		event::sglKeyTyped,
		event::sglMouseMove,
		event::sglMousePressed,
		event::sglMouseReleased,
		event::sglMouseScroll
	>;
}



#endif //!__SGL_CORE_EVENT_CALLBACKS__