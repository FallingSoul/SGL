#ifndef __SGL_CORE_GRAPHICS_WINDOW_WINDOW__
#define __SGL_CORE_GRAPHICS_WINDOW_WINDOW__

#include "sgl/core/family.h"

namespace sgl
{
    namespace core
    {
        namespace graphics
        {
            namespace window
            {
                class SGL_API sglWindow
                { 
                public:
                    sglWindow(const sglWindow &) = delete;
                    sglWindow(const sglChar * name);
                    ~sglWindow();
                    sglVoid close();
                    sglBool is_closed()const;
                    const sglChar * name()const;
                    sglVoid show();
                    sglVoid hide();
                    static sglVoid poll_event();
                    static sglVoid wait_event();
                    static sglVoid wait_event(sglDouble time_out_seconds);


                private:
                    struct sglWindow_Impl * _window;
                };
            }
        }
    }
}


#endif //!__SGL_CORE_GRAPHICS_WINDOW_WINDOW__