#ifndef __SGL_FUNDATION_LANG__
#define __SGL_FUNDATION_LANG__

#include "sgl/fundation/compiler.h"

#ifdef __cplusplus
#define SGL_LANG_CPP 1

#ifdef SGL_CL_MSVC
// '__cplusplus' is always '199711L' in MSVC!
#define SGL_LANG_CPP_STD_NUMBER _MSVC_LANG
#else
#define SGL_LANG_CPP_STD_NUMBER __cplusplus
#endif

#if SGL_LANG_CPP_STD_NUMBER == 199711L
#define SGL_LANG_CPP_STD 98
#elif SGL_LANG_CPP_STD_NUMBER == 201103L
#define SGL_LANG_CPP_STD 11
#elif SGL_LANG_CPP_STD_NUMBER == 201402L
#define SGL_LANG_CPP_STD 14
#elif SGL_LANG_CPP_STD_NUMBER == 201703L
#define SGL_LANG_CPP_STD 17
#elif SGL_LANG_CPP_STD_NUMBER == 202002L
#define SGL_LANG_CPP_STD 20
#elif SGL_LANG_CPP_STD_NUMBER == 202302L
#define SGL_LANG_CPP_STD 23
#endif

#endif


#ifdef __STDC__
#define SGL_LANG_C 1
#define SGL_LANG_C_STD_NUMBER __STDC__VERSION__

#if __STDC__VERSION__ == 199409L
#define SGL_LANG_C_STD 95
#elif __STDC_VERSION__ == 199901L
#define SGL_LANG_C_STD 99
#elif __STDC_VERSION__ == 201112L
#define SGL_LANG_C_STD 11
#elif __STDC_VERSION__ == 201710L
#define SGL_LANG_C_STD 17
#elif __STDC_VERSION__ == 202311L
#define SGL_LANG_C_STD 23
#endif

#endif


#endif //!__SGL_FUNDATION_LANG__