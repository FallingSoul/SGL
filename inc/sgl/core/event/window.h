#ifndef __SGL_CORE_EVENT_WINDOW__
#define __SGL_CORE_EVENT_WINDOW__

#include "sgl/core/event/event.h"

namespace sgl
{
	namespace event
	{
		struct sglWindowCloseInfo
		{
		};
		class sglWindowClose : public sglEvent<sglWindowClose>
		{
		public:
			sglWindowClose(const sglWindowCloseInfo& info)
				:_close_info(info)
			{}
			~sglWindowClose() = default;
			SGL_EVENT_DEFINE(window_close,window)
		private:
			sglWindowCloseInfo _close_info;
		};
		struct sglWindowFocusInfo
		{
			bool focused;
		};
		class sglWindowFocus : public sglEvent<sglWindowFocus>
		{
		public:
			sglWindowFocus(const sglWindowFocusInfo& info)
				:_focus_info(info)
			{}
			~sglWindowFocus() = default;
			bool is_focused() { return this->_focus_info.focused; }
			SGL_EVENT_DEFINE(window_focus,window)
		private:
			sglWindowFocusInfo _focus_info;
		};
		struct sglWindowResizeInfo
		{
			float width,height;
		};
		class sglWindowResize : public sglEvent<sglWindowResize>
		{
		public:
			sglWindowResize(const sglWindowResizeInfo& info)
				:_resize_info(info)
			{}
			~sglWindowResize() = default;
			float get_width() { return this->_resize_info.width; }
			float get_height() { return this->_resize_info.height; }
			SGL_EVENT_DEFINE(window_resize,window)
		private:
			sglWindowResizeInfo _resize_info;
		}; struct sglWindowMoveInfo
		{
			float x, y;
		};
		class sglWindowMove : public sglEvent<sglWindowMove>
		{
		public:
			sglWindowMove(const sglWindowMoveInfo& info)
				:_move_info(info)
			{
			}
			float get_x() { return this->_move_info.x; }
			float get_y() { return this->_move_info.y; }
			~sglWindowMove() = default;
			SGL_EVENT_DEFINE(window_move, window)
		private:
			sglWindowMoveInfo _move_info;
		};
	}
}



#endif //!__SGL_CORE_EVENT_WINDOW__