#ifndef __SGL_CORE_EVENT_KEY__
#define __SGL_CORE_EVENT_KEY__

#include "sgl/core/event/event.h"
#include "sgl/core/keycode.h"

namespace sgl
{
	namespace event
	{
		struct sglKeyPressedInfo
		{
			sglKeyCodeValue key;
			sglModifierKeys mods;
		};
		class sglKeyPressed : public sglEvent<sglKeyPressed>
		{
		public:
			sglKeyPressed(const sglKeyPressedInfo& info)
				:_pressed_info(info)
			{ }
			~sglKeyPressed() = default;
			sglModifierKeys get_mods() { return this->_pressed_info.mods; }
			sglKeyCodeValue get_key() { return this->_pressed_info.key; }
			SGL_EVENT_DEFINE(key_pressed,input | key)
		private:
			sglKeyPressedInfo _pressed_info;
		};
		struct sglKeyReleasedInfo
		{
			sglKeyCodeValue key;
			sglModifierKeys mods;
		};
		class sglKeyReleased : public sglEvent<sglKeyReleased>
		{
		public:
			sglKeyReleased(const sglKeyReleasedInfo& info)
				:_released_info(info)
			{
			}
			~sglKeyReleased() = default;
			sglModifierKeys get_mods() { return this->_released_info.mods; }
			sglKeyCodeValue get_key() { return this->_released_info.key; }
			SGL_EVENT_DEFINE(key_released, input | key)
		private:
			sglKeyReleasedInfo _released_info;
		};
		struct sglKeyTypedInfo
		{
			unsigned int code;
		};
		class sglKeyTyped : public sglEvent<sglKeyTyped>
		{
		public:
			sglKeyTyped(const sglKeyTypedInfo& info)
				:_typed_info(info)
			{ }
			~sglKeyTyped() = default;
			unsigned get_code() { return this->_typed_info.code; }
			SGL_EVENT_DEFINE(key_typed, input | key)
		private:
			sglKeyTypedInfo _typed_info;
		};
	}
}

#endif //!__SGL_CORE_EVENT_KEY__