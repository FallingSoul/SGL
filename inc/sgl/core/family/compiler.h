#ifndef __SGL_CORE_FAMILY_COMPILER__
#define __SGL_CORE_FAMILY_COMPILER__


#if defined(_MSC_VER)
#define SGL_CL_MSVC 1

// for "safe function"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#if _MSC_VER == 1200
#define SGL_CL_MAJOR 6
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1300
#define SGL_CL_MAJOR 7
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1310
#define SGL_CL_MAJOR 7
#define SGL_CL_MINOR 1
#elif _MSC_VER == 1400
#define SGL_CL_MAJOR 8
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1500
#define SGL_CL_MAJOR 9
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1600
#define SGL_CL_MAJOR 10
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1700
#define SGL_CL_MAJOR 11
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1800
#define SGL_CL_MAJOR 12
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1900
#define SGL_CL_MAJOR 14
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1910
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1911
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 3
#elif _MSC_VER == 1912
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 5
#elif _MSC_VER == 1913
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 6
#elif _MSC_VER == 1914
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 7
#elif _MSC_VER == 1915
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 8
#elif _MSC_VER == 1916
#define SGL_CL_MAJOR 15
#define SGL_CL_MINOR 9
#elif _MSC_VER == 1920
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1921
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 1
#elif _MSC_VER == 1922
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 2
#elif _MSC_VER == 1923
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 3
#elif _MSC_VER == 1924
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 4
#elif _MSC_VER == 1925
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 5
#elif _MSC_VER == 1926
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 6
#elif _MSC_VER == 1927
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 7
#elif _MSC_VER == 1928
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 8
#elif _MSC_VER == 1929
#define SGL_CL_MAJOR 16
#define SGL_CL_MINOR 10
#elif _MSC_VER == 1930
#define SGL_CL_MAJOR 17
#define SGL_CL_MINOR 0
#elif _MSC_VER == 1931
#define SGL_CL_MAJOR 17
#define SGL_CL_MINOR 1
#elif _MSC_VER == 1932
#define SGL_CL_MAJOR 17
#define SGL_CL_MINOR 2
#elif _MSC_VER == 1933
#define SGL_CL_MAJOR 17
#define SGL_CL_MINOR 3
#elif _MSC_VER == 1934
#define SGL_CL_MAJOR 17
#define SGL_CL_MINOR 4
#elif _MSC_VER == 1935
#define SGL_CL_MAJOR 17
#define SGL_CL_MINOR 5
#endif

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