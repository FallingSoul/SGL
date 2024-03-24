#ifndef __SGL_CORE_GRAPHICS_WINDOW_WINDOW__
#define __SGL_CORE_GRAPHICS_WINDOW_WINDOW__

#include "sgl/core/family.h"
#include "sgl/core/graphics/window/key.h"

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
                    sglWindow & operator =(const sglWindow &) = delete;
                    sglWindow(const sglChar * name);
                    sglWindow(const sglChar * name,sglInt width,sglInt height);
                    ~sglWindow();
                    sglVoid close();
                    sglBool is_closed()const;
                    const sglChar * name()const;
                    sglVoid show();
                    sglVoid hide();
                    sglKetStatus get_key(sglKeyCode code)const;
                    sglVoid get_size(sglInt & width,sglInt & height)const;
                    sglVoid get_frame_size(sglInt & left,sglInt & top,sglInt & right,sglInt & bottom)const;
                    sglVoid set_user_pointer(sglVoid * ptr);
                    sglVoid * get_user_pointer()const;
                    static sglVoid poll_event();
                    static sglVoid poll_event(sglDouble seconds);
                    static sglVoid wait_event();
                    static sglVoid wait_event(sglDouble time_out_seconds);
                    static sglVoid default_size(sglInt & width,sglInt & height);
                    static const sglChar ** required_extensions(sglInt * count);


                private:
                    struct sglWindow_Impl * _window;
                };
            }
        }
    }
}


#endif //!__SGL_CORE_GRAPHICS_WINDOW_WINDOW__