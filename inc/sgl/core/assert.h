#ifndef __SGL_CORE_ASSERT__
#define __SGL_CORE_ASSERT__

#include <cassert>
#include "sgl/utils/log.h"

#ifdef SGL_DEBUG
#define SGL_ASSERT(condtion,...) if(!(condtion)){SGL_LOG_E(__VA_ARGS__ );std::terminate();}
#else
#define SGL_ASSERT(condtion,...)
#endif

#endif //!__SGL_CORE_ASSERT__