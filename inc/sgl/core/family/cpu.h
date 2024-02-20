#ifndef __SGL_CORE_FAMILY_CPU__
#define __SGL_CORE_FAMILY_CPU__

#include "sgl/core/family/compiler.h"

#if defined(SGL_CL_MSVC)
#if defined(_M_IX86)
#define SGL_CPU_X86 1
#elif defined(_M_X64) || defined(_M_AMD64)
#define SGL_CPU_X64 1
#elif defined(_M_ARM64)
#define SGL_CPU_ARM64 1
#elif defined(_M_ARM)
#define SGL_CPU_ARM32 1
#elif defined(_M_THUMB)
#define SGL_CPU_THUMB 1
#endif
#endif

#if defined(SGL_CL_GCC) || defined(SGL_CL_CLANG)
#if defined(__i386__)
#define SGL_CPU_X86 1
#elif defined(__x86_64__)
#define SGL_CPU_X64 1
#elif defined(__aarch64__)
#define SGL_CPU_ARM64 1
#elif defined(__arm__)
#define SGL_CPU_ARM32 1
#elif defined(__thumb__)
#define SGL_CPU_THUMB 1
#endif

#endif

#endif //!__SGL_CORE_FAMILY_CPU__