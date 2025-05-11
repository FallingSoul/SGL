#ifndef __SGL_CORE_EVEVNT_MOUSE__
#define __SGL_CORE_EVEVNT_MOUSE__


#include "sgl/core/event/event.h"
#include "sgl/core/mousecode.h"

namespace sgl
{
	namespace event
	{
		struct sglMouseMoveInfo
		{
			float x, y;
		};
		class sglMouseMove : public sglEvent<sglMouseMove>
		{
		public:
			sglMouseMove(const sglMouseMoveInfo& info)
				:_move_info(info)
			{}
			~sglMouseMove() = default;
			float get_x() { return this->_move_info.x; }
			float get_y() { return this->_move_info.y; }
			SGL_EVENT_DEFINE(mouse_move,input | mouse)
		private:
			sglMouseMoveInfo _move_info;
		};
		struct sglMousePressedInfo
		{
			sglMouseKeyCode key;
			sglModifierKeys mods;
		};
		class sglMousePressed : public sglEvent<sglMousePressed>
		{
		public:
			sglMousePressed(const sglMousePressedInfo& info)
				:_pressed_info(info)
			{
			}
			~sglMousePressed() = default;
			sglModifierKeys get_mods() { return this->_pressed_info.mods; }
			sglMouseKeyCode get_key() { return this->_pressed_info.key; }
			SGL_EVENT_DEFINE(mouse_pressed, input | mouse)
		private:
			sglMousePressedInfo _pressed_info;

		};
		struct sglMouseReleasedInfo
		{
			sglMouseKeyCode key;
			sglModifierKeys mods;
		};
		class sglMouseReleased : public sglEvent<sglMouseReleased>
		{
		public:
			sglMouseReleased(const sglMouseReleasedInfo& info)
				:_released_info(info)
			{
			}
			~sglMouseReleased() = default;
			sglModifierKeys get_mods() { return this->_released_info.mods; }
			sglMouseKeyCode get_key() { return this->_released_info.key; }
			SGL_EVENT_DEFINE(mouse_released, input | mouse)
		private:
			sglMouseReleasedInfo _released_info;

		};
		struct sglMouseScrollInfo
		{
			float delta_x;
			float delta_y;
		};
		class sglMouseScroll : public sglEvent<sglMouseScroll>
		{
		public:
			sglMouseScroll(const sglMouseScrollInfo& info)
				:_scroll_info(info)
			{
			}
			~sglMouseScroll() = default;
			float get_delta_x() { return this->_scroll_info.delta_x; }
			float get_delta_y() { return this->_scroll_info.delta_y; }
			SGL_EVENT_DEFINE(mouse_scroll, input | mouse)
		private:
			sglMouseScrollInfo _scroll_info;

		};
		
	}
}


#endif //!__SGL_CORE_EVEVNT_MOUSE__