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
        sglException(const sglChar * desc)noexcept:_desc(desc){}
        const sglChar * what()const noexcept{return this->_desc;}
    private:
        const sglChar * _desc;
    };
}

#endif //!__SGL_CORE_FAMILY_EXCEPTION__