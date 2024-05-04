#ifndef __SGL_CORE_WINDOWS_CONTEXT__
#define __SGL_CORE_WINDOWS_CONTEXT__


#include "sgl/core/family.h"

namespace sgl
{
    namespace core
    {
        class SGL_API sglWindowContext
        {
        public:
            const sglWindowContext & operator= (const sglWindowContext &) = delete;
            sglWindowContext(const sglWindowContext &) = delete;
            sglWindowContext();
            sglWindowContext(sglInt opengl_major,sglInt opengl_minor);
            ~sglWindowContext();
            sglVoid poll_events();
            sglDouble get_time();
            static void error_callback(int code,const char * errstr);
        };
    }
}

#endif //__SGL_CORE_WINDOWS_CONTEXT__
