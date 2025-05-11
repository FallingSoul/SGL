#ifndef __SGL_FUNDATION_CONFIG__
#define __SGL_FUNDATION_CONFIG__

#include "sgl/fundation/type.h"
#include "sgl/fundation/compiler.h"

#define SGL_EXPORT __declspec(dllexport)
#define SGL_IMPORT __declspec(dllimport)
#ifdef SGL_BUILD
#define SGL_API SGL_EXPORT
#else
#define SGL_API SGL_IMPORT
#endif

#ifdef _DEBUG
#define SGL_DEBUG 1
#endif

#define SGL_BIT(bit) (1 << (bit))

namespace sgl
{
    struct sglLibraryInfo
    {
        const char* name = SGL_LIBRARY_NAME;
        struct
        {
            int major, minor, patch;
        }version =
        {
            .major = SGL_VERSION_MAJOR,
            .minor = SGL_VERSION_MINOR,
            .patch = SGL_VERSION_PATCH
        };
    };

    using sglCompilerInfo = sglLibraryInfo;



    extern "C"
    {
        SGL_API sglLibraryInfo sglGetLibraryInfo();

        SGL_API sglCompilerInfo sglGetCompilerInfo();

        SGL_API long sglGetLanguageStd();
        
        SGL_API bool sglIsRequiredLibrary(const sglLibraryInfo required = sglLibraryInfo());
    }
}

#endif //!__SGL_FUNDATION_CONFIG__