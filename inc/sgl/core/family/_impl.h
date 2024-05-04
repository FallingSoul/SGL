#ifndef __SGL_CORE__IMPL__
#define __SGL_CORE__IMPL__

#include "sgl/core/family/config.h"
#include "sgl/core/family/type.h"

namespace sgl
{
    namespace core
    {
        template<typename Target>
        class sgl_Impl
        {
        public:
            sgl_Impl(const sgl_Impl & impl)
                :_target(new Target(*impl._target))
            {}
            sgl_Impl(const Target & target)
                :_target(new Target(target))
            {}
            template<typename T>
            sgl_Impl(const sgl_Impl<T> & impl)
                :_target(new Target(*impl._target))
            {}
            template<typename T>
            sgl_Impl(const T & target)
                :_target(new Target(target))
            {}
            template<typename ... Args>
            sgl_Impl(Args ... args)
                :_target(new Target(args...))
            {}
            sgl_Impl()
                :_target(new Target())
            {}
            ~sgl_Impl()
            {
                delete this->_target;
                this->_target = nullptr;
            }
            sglBool invalid()const noexcept
            {
                return nullptr == this->_target;
            }
            const Target * operator-> ()const noexcept
            {
                return this->_target;
            }
            Target * operator-> ()noexcept
            {
                return this->_target;
            }
            Target * get()noexcept
            {
                return this->_target;
            }
            const Target * get()const noexcept
            {
                return this->_target;
            }
            auto operator= (const sgl_Impl & impl)
            {
                return *this->_target = *impl._target;
            }
            auto operator= (const Target & target)
            {
                return *this->_target = target;
            }
            template<typename T>
            auto operator= (const sgl_Impl<T> & impl)
            {
                return *this->_target = *impl._target;
            }
            template<typename T>
            auto operator= (const T & target)
            {
                return *this->_target = target;
            }

        private:
            Target * _target;
        };
    }
}

#endif //!__SGL_CORE__IMPL__