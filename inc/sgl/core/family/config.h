#ifndef __SGL_CORE_FAMILY_CONFIG__
#define __SGL_CORE_FAMILY_CONFIG__

#include "sgl/core/family/type.h"
#include "sgl/core/family/compiler.h"

#define SGL_EXPORT __declspec(dllexport)
#define SGL_IMPORT __declspec(dllimport)
#ifdef SGL_BUILD
#define SGL_API SGL_EXPORT
#else
#define SGL_API SGL_IMPORT
#endif

namespace sgl
{
    struct sglConfigInfo
    {
        const sglChar * name;
        struct
        {
            sglInt major,minor,patch;
        }version;
    };
    SGL_API sglConfigInfo sglGetConfigInfo();
    SGL_API sglConfigInfo sglGetCompilerInfo();
}

#endif //!__SGL_CORE_FAMILY_CONFIG__