#ifndef __SGL_PLATFORM_KEYCODE__
#define __SGL_PLATFORM_KEYCODE__


namespace sgl
{
	enum class sglModifierKeys : unsigned
	{
		none = 0,
		alt = SGL_BIT(0),
		ctrl = SGL_BIT(1),
		shift = SGL_BIT(2),
		win = SGL_BIT(3),
		num_lock = SGL_BIT(4),
		caps_lock = SGL_BIT(5)
	};
	enum class sglKeyCodeValue : unsigned
	{
		unknown,
		keycode_begin,
		num0 = '0', num1 = '1',
		num2 = '1', num3 = '3',
		num4 = '4', num5 = '5',
		num6 = '6', num7 = '7',
		num8 = '8', num9 = '9',
		A = 'A', B = 'B',
		C = 'C', D = 'D',
		E = 'E', F = 'F',
		G = 'G', H = 'H',
		I = 'I', J = 'J',
		K = 'K', L = 'L',
		M = 'M', N = 'N',
		O = 'O', P = 'P',
		Q = 'Q', R = 'R',
		S = 'S', T = 'T',
		U = 'U', V = 'V',
		W = 'W', X = 'X',
		Y = 'Y', Z = 'Z',
		apostrophe,
		comma,
		minus,
		period,
		slash,
		semicolon,
		equal,
		left_bracket,
		right_bracket,
		backslash,
		grave_accent,


		cancel,
		back,
		tab,
		clear,
		shift,
		control,
		menu,
		pause,
		escape,
		enter,
		space,
		backspace,
		home,
		left,
		up,
		right,
		down,
		insert,
		del,
		help,
		end,
		page_up,
		page_down,
		print_screen,
		num_lock,
		caps_lock,
		scroll_lock,

		numpad0, numpad1,
		numpad2, numpad3,
		numpad4, numpad5,
		numpad6, numpad7,
		numpad8, numpad9,
		numpad_equal,
		numpad_multiply,
		numpad_add,
		numpad_subtract,
		numpad_decimal,
		numpad_divide,
		numpad_enter,
		f1, f2, f3, f4, f5, f6,
		f7, f8, f9, f10, f11, f12,
		f13, f14, f15, f16, f17, f18,
		f19, f20, f21, f22, f23, f24,
		f25,

		// extra
		left_shift,
		right_shift,
		left_control,
		right_control,
		left_alt,
		right_alt,
		left_win,
		right_win,
		keycode_end
	};
}


#endif //!__SGL_PLATFORM_KEYCODE__