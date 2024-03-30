#ifndef __SGL_CORE_FAMILY_EXCEPTION__
#define __SGL_CORE_FAMILY_EXCEPTION__

#include <exception>

#include "sgl/core/family/config.h"
#include "sgl/core/family/type.h"

namespace sgl
{
    class sglException : public std::exception
    {
    public:
        sglException(const sglChar * desc)noexcept:_desc(desc),_addtion(nullptr),_code(~0){}
        sglException(const sglChar * desc,const sglChar * addtion)noexcept:_desc(desc),_addtion(addtion),_code(~0){}
        sglException(const sglChar * desc,const sglUInt code)noexcept:_desc(desc),_addtion(nullptr),_code(code){}
        sglException(const sglChar * desc,const sglChar * addtion,const sglInt code)noexcept:_desc(desc),_addtion(addtion),_code(code){}
        const sglChar * what()const noexcept{return this->_desc;}
        const sglChar * other()const noexcept{return this->_addtion;}
    private:
        const sglChar * _desc;
        const sglChar * _addtion;
        sglUInt _code;
    };
}

#endif //!__SGL_CORE_FAMILY_EXCEPTION__