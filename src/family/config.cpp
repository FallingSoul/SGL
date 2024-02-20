#include "sgl/core/family/config.h"

#define STRING(str) #str

namespace sgl
{
    static sglConfigInfo sgl_config_info = 
    {
        "SGL",
        SGL_VERSION_MAJOR,
        SGL_VERSION_MINOR,
        SGL_VERSION_PATCH
    };
    static sglConfigInfo sgl_compiler_info =
    {
#if defined(SGL_CL_MSVC)
        "MSVC",
#elif defined(SGL_CL_CLANG)
        "CLANG",
#elif defined(SGL_CL_GCC)
        "GCC",
#else
        "Unknown",
#endif
        SGL_CL_MAJOR,
        SGL_CL_MINOR,
        SGL_CL_PATCH
    };
    sglConfigInfo sglGetConfigInfo()
    {
        return sgl_config_info;
    }
    
    sglConfigInfo sglGetCompilerInfo()
    {
        return sgl_compiler_info;
    }
}