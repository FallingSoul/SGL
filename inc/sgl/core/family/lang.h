#ifndef __SGL_CORE_FAMILY_LANG__
#define __SGL_CORE_FAMILY_LANG__


#ifdef __cplusplus
#define SGL_LANG_CPP 1

#if __cplusplus == 199711L
#define SGL_LANG_CPP_STD 98
#elif __cplusplus == 201103L
#define SGL_LANG_CPP_STD 11
#elif __cplusplus == 201402L
#define SGL_LANG_CPP_STD 14
#elif __cplusplus == 201703L
#define SGL_LANG_CPP_STD 17
#elif __cplusplus == 202002L
#define SGL_LANG_CPP_STD 20
#elif __cplusplus == 202302L
#define SGL_LANG_CPP_STD 23
#endif

#endif

#ifdef __STDC__
#define SGL_LANG_C 1

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


#endif //!__SGL_CORE_FAMILY_LANG__