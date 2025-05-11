#include <GLFW/glfw3.h>
#include "sgl/platform/keymap.h"

namespace sgl
{

	static std::map<int, sglKeyCodeValue> key_map =
	{
		{GLFW_KEY_SPACE,sglKeyCodeValue::space},
		{GLFW_KEY_APOSTROPHE,sglKeyCodeValue::apostrophe},
		{GLFW_KEY_COMMA,sglKeyCodeValue::comma},
		{GLFW_KEY_MINUS,sglKeyCodeValue::minus},
		{GLFW_KEY_PERIOD,sglKeyCodeValue::period},
		{GLFW_KEY_SLASH,sglKeyCodeValue::slash},
		{GLFW_KEY_BACKSLASH,sglKeyCodeValue::backslash},
		{GLFW_KEY_SEMICOLON,sglKeyCodeValue::semicolon},
		{GLFW_KEY_EQUAL,sglKeyCodeValue::equal},
		{GLFW_KEY_LEFT_BRACKET,sglKeyCodeValue::left_bracket},
		{GLFW_KEY_RIGHT_BRACKET,sglKeyCodeValue::right_bracket},
		{GLFW_KEY_GRAVE_ACCENT,sglKeyCodeValue::grave_accent},

		{GLFW_KEY_ESCAPE,sglKeyCodeValue::escape},
		{GLFW_KEY_ENTER,sglKeyCodeValue::enter},
		{GLFW_KEY_TAB,sglKeyCodeValue::tab},
		{GLFW_KEY_BACKSPACE,sglKeyCodeValue::backspace},
		{GLFW_KEY_INSERT,sglKeyCodeValue::insert},
		{GLFW_KEY_DELETE,sglKeyCodeValue::del},
		{GLFW_KEY_RIGHT,sglKeyCodeValue::right},
		{GLFW_KEY_LEFT,sglKeyCodeValue::left},
		{GLFW_KEY_UP,sglKeyCodeValue::up},
		{GLFW_KEY_DOWN,sglKeyCodeValue::down},
		{GLFW_KEY_PAGE_UP,sglKeyCodeValue::page_up},
		{GLFW_KEY_PAGE_DOWN,sglKeyCodeValue::page_down},
		{GLFW_KEY_HOME,sglKeyCodeValue::home},
		{GLFW_KEY_END,sglKeyCodeValue::end},
		{GLFW_KEY_CAPS_LOCK,sglKeyCodeValue::caps_lock},
		{GLFW_KEY_SCROLL_LOCK,sglKeyCodeValue::scroll_lock},
		{GLFW_KEY_NUM_LOCK,sglKeyCodeValue::num_lock},
		{GLFW_KEY_PRINT_SCREEN,sglKeyCodeValue::print_screen},
		{GLFW_KEY_PAUSE,sglKeyCodeValue::pause},
		{GLFW_KEY_F1,sglKeyCodeValue::f1},
		{GLFW_KEY_F2,sglKeyCodeValue::f2},
		{GLFW_KEY_F3,sglKeyCodeValue::f3},
		{GLFW_KEY_F4,sglKeyCodeValue::f4},
		{GLFW_KEY_F5,sglKeyCodeValue::f5},
		{GLFW_KEY_F6,sglKeyCodeValue::f6},
		{GLFW_KEY_F7,sglKeyCodeValue::f7},
		{GLFW_KEY_F8,sglKeyCodeValue::f8},
		{GLFW_KEY_F9,sglKeyCodeValue::f9},
		{GLFW_KEY_F10,sglKeyCodeValue::f10},
		{GLFW_KEY_F11,sglKeyCodeValue::f11},
		{GLFW_KEY_F12,sglKeyCodeValue::f12},
		{GLFW_KEY_F13,sglKeyCodeValue::f13},
		{GLFW_KEY_F14,sglKeyCodeValue::f14},
		{GLFW_KEY_F15,sglKeyCodeValue::f15},
		{GLFW_KEY_F16,sglKeyCodeValue::f16},
		{GLFW_KEY_F17,sglKeyCodeValue::f17},
		{GLFW_KEY_F18,sglKeyCodeValue::f18},
		{GLFW_KEY_F19,sglKeyCodeValue::f19},
		{GLFW_KEY_F20,sglKeyCodeValue::f20},
		{GLFW_KEY_F21,sglKeyCodeValue::f21},
		{GLFW_KEY_F22,sglKeyCodeValue::f22},
		{GLFW_KEY_F23,sglKeyCodeValue::f23},
		{GLFW_KEY_F24,sglKeyCodeValue::f24},
		{GLFW_KEY_F25,sglKeyCodeValue::f25},
		{GLFW_KEY_KP_0,sglKeyCodeValue::numpad0},
		{GLFW_KEY_KP_1,sglKeyCodeValue::numpad1},
		{GLFW_KEY_KP_2,sglKeyCodeValue::numpad2},
		{GLFW_KEY_KP_3,sglKeyCodeValue::numpad3},
		{GLFW_KEY_KP_4,sglKeyCodeValue::numpad4},
		{GLFW_KEY_KP_5,sglKeyCodeValue::numpad5},
		{GLFW_KEY_KP_6,sglKeyCodeValue::numpad6},
		{GLFW_KEY_KP_7,sglKeyCodeValue::numpad7},
		{GLFW_KEY_KP_8,sglKeyCodeValue::numpad8},
		{GLFW_KEY_KP_9,sglKeyCodeValue::numpad9},
		{GLFW_KEY_KP_DECIMAL,sglKeyCodeValue::numpad_decimal},
		{GLFW_KEY_KP_DIVIDE,sglKeyCodeValue::numpad_divide},
		{GLFW_KEY_KP_MULTIPLY,sglKeyCodeValue::numpad_multiply},
		{GLFW_KEY_KP_SUBTRACT,sglKeyCodeValue::numpad_subtract},
		{GLFW_KEY_KP_ADD,sglKeyCodeValue::numpad_add},
		{GLFW_KEY_KP_ENTER,sglKeyCodeValue::numpad_enter},
		{GLFW_KEY_KP_EQUAL,sglKeyCodeValue::numpad_equal},
		{GLFW_KEY_LEFT_SHIFT,sglKeyCodeValue::left_shift},
		{GLFW_KEY_LEFT_CONTROL,sglKeyCodeValue::left_control},
		{GLFW_KEY_LEFT_ALT,sglKeyCodeValue::left_alt},
		{GLFW_KEY_LEFT_SUPER,sglKeyCodeValue::left_win},
		{GLFW_KEY_RIGHT_SHIFT,sglKeyCodeValue::right_shift},
		{GLFW_KEY_RIGHT_CONTROL,sglKeyCodeValue::right_control},
		{GLFW_KEY_RIGHT_ALT,sglKeyCodeValue::right_alt},
		{GLFW_KEY_RIGHT_SUPER,sglKeyCodeValue::right_win},
		{GLFW_KEY_MENU,sglKeyCodeValue::menu},

		{GLFW_KEY_UNKNOWN,sglKeyCodeValue::unknown}
		// 0~9
	};
	static std::map<int, sglMouseKeyCode> mouse_key_map =
	{
		{GLFW_MOUSE_BUTTON_LEFT,sglMouseKeyCode::left_button},
		{GLFW_MOUSE_BUTTON_RIGHT,sglMouseKeyCode::right_button},
		{GLFW_MOUSE_BUTTON_MIDDLE,sglMouseKeyCode::middle_button},
		{GLFW_MOUSE_BUTTON_1,sglMouseKeyCode::button1},
		{GLFW_MOUSE_BUTTON_2,sglMouseKeyCode::button2},
		{GLFW_MOUSE_BUTTON_3,sglMouseKeyCode::button3},
		{GLFW_MOUSE_BUTTON_4,sglMouseKeyCode::button4},
		{GLFW_MOUSE_BUTTON_5,sglMouseKeyCode::button5},
		{GLFW_MOUSE_BUTTON_6,sglMouseKeyCode::button6},
		{GLFW_MOUSE_BUTTON_7,sglMouseKeyCode::button7},
		{GLFW_MOUSE_BUTTON_8,sglMouseKeyCode::button8}
	};
	sglMouseKeyCode map_mouse_key(int glfw_key)
	{
		return mouse_key_map.at(glfw_key);
	}
	int map_mouse_key(sglMouseKeyCode key)
	{
		auto it = std::find_if(mouse_key_map.begin(), mouse_key_map.end(), [&key](const auto& item) {return key == item.second; });
		if (mouse_key_map.end() == it)
			return -1;// Unknown
		return it->first;
	}
	sglKeyCodeValue map_key(int glfw_key)
	{
		if (
			('0' <= glfw_key && '9' >= glfw_key) ||
			('A' <= glfw_key && 'Z' >= glfw_key)
			)
			return sglKeyCodeValue(glfw_key);
		return key_map.at(glfw_key);
	}
	int map_key(sglKeyCodeValue key)
	{
		if ((sglKeyCodeValue::num0 <= key && sglKeyCodeValue::num9 >= key) ||
			sglKeyCodeValue::A <= key && sglKeyCodeValue::Z >= key)
			return int(key);
		auto it = std::find_if(key_map.begin(), key_map.end(), [&key](const auto& item) {return key == item.second; });
		if (key_map.end() == it)
			return GLFW_KEY_UNKNOWN;
		return it->first;
	}
	sglModifierKeys map_mods(int glfw_mods)
	{
		sglModifierKeys ret = sglModifierKeys::none;
		if (GLFW_MOD_ALT & glfw_mods)ret = sglModifierKeys(unsigned(ret) | unsigned(sglModifierKeys::alt));
		if (GLFW_MOD_CONTROL & glfw_mods)ret = sglModifierKeys(unsigned(ret) | unsigned(sglModifierKeys::ctrl));
		if (GLFW_MOD_SHIFT & glfw_mods)ret = sglModifierKeys(unsigned(ret) | unsigned(sglModifierKeys::shift));
		if (GLFW_MOD_SUPER & glfw_mods)ret = sglModifierKeys(unsigned(ret) | unsigned(sglModifierKeys::win));
		if (GLFW_MOD_CAPS_LOCK & glfw_mods)ret = sglModifierKeys(unsigned(ret) | unsigned(sglModifierKeys::caps_lock));
		if (GLFW_MOD_NUM_LOCK & glfw_mods)ret = sglModifierKeys(unsigned(ret) | unsigned(sglModifierKeys::num_lock));
		return ret;
	}
	int map_mods(sglModifierKeys mods)
	{
		int ret = 0;
		if (unsigned(mods) | unsigned(sglModifierKeys::alt))ret |= GLFW_MOD_ALT;
		if (unsigned(mods) | unsigned(sglModifierKeys::ctrl))ret |= GLFW_MOD_CONTROL;
		if (unsigned(mods) | unsigned(sglModifierKeys::shift))ret |= GLFW_MOD_SHIFT;
		if (unsigned(mods) | unsigned(sglModifierKeys::win))ret |= GLFW_MOD_SUPER;
		if (unsigned(mods) | unsigned(sglModifierKeys::caps_lock))ret |= GLFW_MOD_CAPS_LOCK;
		if (unsigned(mods) | unsigned(sglModifierKeys::num_lock))ret |= GLFW_MOD_NUM_LOCK;
		return ret;
	}

	// For Key Mapping API
	sglMouseKeyCode sglMapMouseKey(int key)
	{
		return map_mouse_key(key);
	}
	sglModifierKeys sglMapMods(int mods)
	{
		return map_mods(mods);
	}
	sglKeyCodeValue sglMapKey(int key)
	{
		return map_key(key);
	}

	int sglMapMouseKey(sglMouseKeyCode key)
	{
		return map_mouse_key(key);
	}
	int sglMapMods(sglModifierKeys mods)
	{
		return map_mods(mods);
	}
	int sglMapKey(sglKeyCodeValue key)
	{
		return map_key(key);
	}
}