#ifndef __SGL_CORE_WINDOWS_WINDOW__
#define __SGL_CORE_WINDOWS_WINDOW__

#include <string>

#include "sgl/core/family.h"

#include "sgl/core/windows/keycode.h"

namespace sgl
{
    namespace core
    {

        class SGL_API sglWindow
        {
        public:
            const sglWindow & operator= (const sglWindow &) = delete;
            sglWindow(const sglWindow &) = delete;
            sglWindow(const sglChar * name,sglInt width,sglInt height);
            ~sglWindow();
            sglVoid show();
            sglBool shown()const;
            sglVoid hide();
            sglBool hidden()const;
            sglVoid close();
            sglBool closed()const;
            std::string name()const;
            sglBool key_pressed(sglKeyCode vkey)const;
            sglBool key_released(sglKeyCode vkey)const;
        private:
            sgl_Impl<struct sglWindow_Impl> window;
        };
    }
}

#endif //!__SGL_CORE_WINDOWS_WINDOW__