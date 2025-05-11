#ifndef __SGL_FUNDATION_SYSTEM__
#define __SGL_FUNDATION_SYSTEM__

#ifdef __STDC_HOSTED__

#define SGL_HOST_SYSTEM 1

#if defined(_WIN64)
#define SGL_SYS_WIN64 1
#define SGL_SYS_NAME "win64"
#elif defined(_WIN32)
#define SGL_SYS_WIN32 1
#define SGL_SYS_WINDOWS 1
#define SGL_SYS_NAME "win32"
#endif

#if defined(__linux__)
#define SGL_SYS_LINUX 1
#define SGL_SYS_NAME "linux"
#endif

#if defined(__unix__)
#define SGL_SYS_UNIX 1
#define SGL_SYS_NAME "unix"
#endif

#if defined(__ADNROID__)
#define SGL_SYS_ANDROID 1
#endif

#if defined(__APPLE__) || defined(__MACH__)
#define SGL_SYS_APPLE 1

#include <TargetConditionals.h>

#if defined(TARGET_OS_EMBEDDED)
#define SGL_SYS_APPLE_EMBEDDED 1
#define SGL_SYS_NAME "apple embedded"
#endif

#if defined(TARGET_IPHONE_SIMULATOR)
#define SGL_SYS_APPLE_IPHONE_SIMULATOR 1
#define SGL_SYS_NAME "apple iphone simulator"
#endif

#if defined(TARGET_OS_IPHONE)
#define SGL_SYS_APPLE_IPHONE 1
#define SGL_SYS_NAME "apple iphone"
#endif

#ifdef defined(TARGET_OS_MAC)
#define SGL_SYS_APPLE_MAC 1
#define SGL_SYS_NAME "apple mac"
#endif

#endif

#if defined(_POSIX_VERSION)
#define SGL_SYS_CYGWIN 1
#define SGL_SYS_NAME "cygwin"
#endif

#if defined(__sun)
#define SGL_SYS_SOLARIS 1
#define SGL_SYS_NAME "solaris"
#endif

#if defined(__hpux)
#define SGL_SYS_HPUX 1
#define SGL_SYS_NAME "hpux"
#endif

#if defined(BSD)
#define SGL_SYS_BSD 1

#if defined(__DragonFly__)
#define SGL_SYS_BSD_DRAGONFLY 1
#define SGL_SYS_NAME "bsd dragonfly"
#endif

#if defined(__FreeBSD__)
#define SGL_SYS_BSD_FREE 1
#define SGL_SYS_NAME "bsd free"
#endif

#if defined(__NetBSD__)
#define SGL_SYS_BSD_NET 1
#define SGL_SYS_NAME "bsd net"
#endif

#if defined(__OpenBSD__)
#define SGL_SYS_BSD_OPEN 1
#define SGL_SYS_NAME "bsd open"
#endif

#endif

#ifndef SGL_SYS_NAME
// There will be some uncertainty
#define SGL_SYS_UNKNOWN 1
#define SGL_SYS_NAME "unknown"
#endif

#endif


#endif //!__SGL_FUNDATION_SYSTEM__