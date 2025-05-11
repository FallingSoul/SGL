#ifndef __SGL_UTILS_CODECVT__
#define __SGL_UTILS_CODECVT__



namespace sgl
{	
	std::string sglUnicodeToUTF8(const std::wstring & str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> wcv;
		return wcv.to_bytes(str);
	}
	std::wstring sglUTF8ToUnicode(const std::string& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> wcv;
		return wcv.from_bytes(str);
	}
}


#endif //!__SGL_UTILS_CODECVT__