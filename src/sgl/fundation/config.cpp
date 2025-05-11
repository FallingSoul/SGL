#include "sgl/fundation/config.h"


namespace sgl
{
	static sglLibraryInfo __sgl_config_info__
	{
		SGL_LIBRARY_NAME,
		{SGL_VERSION_MAJOR,SGL_VERSION_MINOR,SGL_VERSION_PATCH}
	};
	static sglCompilerInfo __sgl_compiler_info__
	{
#if defined(SGL_CL_MSVC)
		"MSVC"
#elif defined(SGL_CL_GCC)
		"GCC"
#elif defined(SGL_CL_CLANG)
		"CLANG"
#endif
		,
		{SGL_CL_MAJOR,SGL_CL_MINOR,SGL_CL_PATCH}
	};
	sglLibraryInfo sglGetLibraryInfo()
	{
		return __sgl_config_info__;
	}
	sglCompilerInfo sglGetCompilerInfo()
	{
		return __sgl_compiler_info__;
	}
	long sglGetLanguageStd()
	{
#if defined(SGL_LANG_CPP_STD)
		return SGL_LANG_CPP_STD;
#elif defined(SGL_LANG_C_STD)
		return SGL_LANG_C_STD;
#else
#error "wrong language! neither cpp nor c!"
#endif
	}
	bool sglIsRequiredLibrary(const sglLibraryInfo required)
	{
		if (0 != strcmp(__sgl_config_info__.name, required.name))
			return false;
		if (__sgl_config_info__.version.major < required.version.major)
			return false;
		if (__sgl_config_info__.version.minor < required.version.major)
			return false;
		if (0 != required.version.patch && __sgl_config_info__.version.patch < required.version.patch)
			return false;
		return true;
	}
}