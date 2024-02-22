#ifndef __SGL_CORE_FAMILY_COMPILER__
#define __SGL_CORE_FAMILY_COMPILER__


#if defined(_MSC_VER)
#define SGL_CL_MSVC 1

// for "safe function"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

// _MSC_VER = Major Major Minor Minor
// _MSC_FULL_VER = _MSC_VER Inside Inside Inside Inside
// _MSC_BUILD = Patch
#define SGL_CL_MAJOR (_MSC_VER / 100)
#define SGL_CL_MINOR (_MSC_VER - SGL_CL_MAJOR * 100)
#define SGL_CL_PATCH _MSC_BUILD

#endif


#if defined(__clang__)
#define SGL_CL_CLANG 1

#define SGL_CL_MAJOR __clang_major__
#define SGL_CL_MINOR __clang_minor__
#define SGL_CL_PATCH __clang_patchlevel__

#elif defined(__GNUC__)
#define SGL_CL_GCC 1

#define SGL_CL_MAJOR __GNUC__
#define SGL_CL_MINOR __GNUC_MINOR__

#if __GNUC__ >= 3
#define SGL_CL_PATCH __GNUC_PATCHLEVEL__
#endif

#endif


#if !defined(SGL_CL_MAJOR)
#define SGL_CL_MAJOR 0
#endif
#if !defined(SGL_CL_MINOR)
#define SGL_CL_MINOR 0
#endif
#if !defined(SGL_CL_PATCH)
#define SGL_CL_PATCH 0
#endif


#endif //!__SGL_CORE_FAMILY_COMPILER__