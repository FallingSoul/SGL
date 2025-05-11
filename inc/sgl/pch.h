#ifndef __SGL_PCH__
#define __SGL_PCH__

// C
#include <stdio.h>
// Cpp

#include <mutex>
#include <thread>
#include <chrono>
#include <codecvt>
#include <cassert>
#include <iostream>
#include <functional>
#include <type_traits>

#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <array>
#include <map>
#include <any>
#include <new>



// SGL
#include "sgl/fundation.h"
#include "sgl/core.h"

// System
#if defined(SGL_SYS_WINDOWS) || defined(SGL_SYS_WIN64)
#define UNICODE
#include <Windows.h>
#endif

#endif //!__SGL_PCH__