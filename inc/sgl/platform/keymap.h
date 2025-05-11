#ifndef __SGL_PLATFORM_KEY_MAP__
#define __SGL_PLATFORM_KEY_MAP__


namespace sgl
{
	SGL_API sglKeyCodeValue sglMapKey(int key);
	SGL_API int sglMapKey(sglKeyCodeValue key);
	SGL_API sglModifierKeys sglMapMods(int mods);
	SGL_API int sglMapMods(sglModifierKeys mods);


	SGL_API sglMouseKeyCode sglMapMouseKey(int key);
	SGL_API int sglMapMouseKey(sglMouseKeyCode key);
}
#endif //!__SGL_PLATFORM_KEY_MAP__