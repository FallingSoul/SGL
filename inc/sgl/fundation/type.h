#ifndef __SGL_FUNDATION_TYPE__
#define __SGL_FUNDATION_TYPE__

#include <stdint.h>
#include <memory>
#include "sgl/fundation/config.h"



namespace sgl
{
	struct __sglImplConstruction__ {};
	template<class Self> 
	class __sgl_Self__
	{
	public:
		__sgl_Self__(__sgl_Self__&&) = default;
		__sgl_Self__(const __sgl_Self__&) = default;
		__sgl_Self__() = default;
		~__sgl_Self__() = default;
		__sgl_Self__& operator= (const __sgl_Self__&) = default;
	public:

		template<class Derived,class ... Args>
		static __sgl_Self__ make(Args&& ... args)
		{
			return __sgl_Self__(std::make_unique<Derived>(args...));
		}

		template<class Derived>
		Derived* dynamic_self_cast() 
		{
			return dynamic_cast<Derived*>(this->_self.get());
		}
		template<class Derived>
		const Derived* dynamic_self_cast()const
		{
			return dynamic_cast<Derived*>(this->_self.get());
		}
		Self* get() { return this->_self.get(); }
		const Self* get()const { return this->_self.get(); }

		Self* operator-> () { return this->_self.get(); }
		const Self* operator-> ()const { return this->_self.get(); }

		Self& operator* () { return *this->_self; }
		const Self& operator* ()const { return *this->_self; }
	private:
		__sgl_Self__(std::unique_ptr<Self>&& self)
			:_self(std::forward<std::unique_ptr<Self>>(self))
		{}
	private:
		std::unique_ptr<Self> _self = nullptr;
	};
}



#endif //!__SGL_FUNDATION_TYPE__