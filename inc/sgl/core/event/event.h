#ifndef __SGL_CORE_EVENT_EVENT__
#define __SGL_CORE_EVENT_EVENT__


namespace sgl
{
	template<class T>
	class sglEvent
	{
	public:
		enum sglEventType
		{
			none,
			//window
			window_close,
			window_resize,
			window_focus,
			window_move,
			//input
			key_pressed,
			key_released,
			key_typed,
			mouse_pressed,
			mouse_released,
			mouse_move,
			mouse_scroll,
			// client
			tick,
			update,
			// user
			user
		};
		enum sglEventCategory
		{
			window = SGL_BIT(0),
			input = SGL_BIT(1),
			key = SGL_BIT(2),
			mouse = SGL_BIT(3),
			client = SGL_BIT(4)
		};
		static constexpr sglEventType get_type()
		{
			return T::get_type();
		}
		static constexpr sglEventCategory get_category()
		{
			return T::get_category();
		}
		static const char* get_type_name()
		{
			return T::get_type_name();
		}
		void add_handled_times() { this->_handled_times++; }
		int get_handled_times() { return this->_handled_times; }
		sglEvent() = default;
		~sglEvent() = default;
	private:
		int _handled_times = 0;
	};
}
#define SGL_EVENT_DEFINE(type,catgory)\
	static constexpr sglEventType get_type(){return sglEventType(type);}\
	static constexpr sglEventCategory get_category() { return sglEventCategory(catgory); }\
	static const char* get_type_name(){return #type;}


#endif //!__SGL_CORE_EVENT_EVENT__