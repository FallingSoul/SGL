#ifndef __SGL_CORE_GRAPHICS_WINDOW_KEY__
#define __SGL_CORE_GRAPHICS_WINDOW_KEY__



#include "sgl/core/family.h"


namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace window
            {
                enum class sglKetStatus
                {
                    Invalid = ~0,
                    Release,
                    Press,
                    Repeat
                };
                enum class sglKeyCode
                {
                    Key_Invalid = ~0,
                    Key_A = 65,Key_B = 66,Key_C = 67,Key_D = 68,
                    Key_E = 69,Key_F = 70,Key_G = 71,Key_H = 72,
                    Key_I = 73,Key_J = 74,Key_K = 75,Key_L = 76,
                    Key_M = 77,Key_N = 78,Key_O = 79,Key_P = 80,
                    Key_R = 81,Key_S = 82,Key_T = 83,Key_U = 84,
                    Key_V = 85,Key_W = 86,Key_X = 87,Key_Y = 88,
                    Key_Z = 89,

                    Key_0 = 48,Key_1 = 49,Key_2 = 50,Key_3 = 51,
                    Key_4 = 52,Key_5 = 53,Key_6 = 54,Key_7 = 55,
                    Key_8 = 56,Key_9 = 57,

                    Key_Num0 = 96,Key_Num1 = 97,Key_Num2 = 98,Key_Num3 = 99,
                    Key_Num4 = 100,Key_Num5 = 101,Key_Num6 = 102,Key_Num7 = 103,
                    Key_Num8 = 104,Key_Num9 = 105,

                    Key_Multiply = 106,Key_Add = 107,Key_Return = 108,Key_Subtract = 109,
                    Key_Decimal = 110,Key_Divide = 111,

                    Key_F1 = 112,Key_F2 = 113,Key_F3 = 114,Key_F4 = 115,
                    Key_F5 = 116,Key_F6 = 117,Key_F7 = 118,Key_F8 = 119,
                    Key_F9 = 120,Key_F10 = 121,Key_F11 = 122,Key_F12 = 123

                };
            }
        }
    }
}

#endif //!__SGL_CORE_GRAPHICS_WINDOW_KEY__