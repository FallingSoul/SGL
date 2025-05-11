#ifndef __SGL_FUNDATION_REF__
#define __SGL_FUNDATION_REF__


namespace sgl
{
	template<class T>
	class sglRef
	{
	public:
		sglRef(const sglRef&) = default;
		sglRef(sglRef&&) = default;
		sglRef() = default;
		~sglRef() = default;
		sglRef& operator=(const sglRef&) = default;
	public:
		explicit sglRef(T* t)
			:_ptr(t)
		{}
		explicit sglRef(std::shared_ptr<T> ptr)
			:_ptr(ptr)
		{
		}

		template<class E>
		sglRef<E> dynamic_ref_cast()
		{
			return sglRef<E>(std::dynamic_pointer_cast<E>(this->_ptr));
		}
		template<class E>
		sglRef<E> static_ref_cast()
		{
			return sglRef<E>(std::static_pointer_cast<E>(this->_ptr));
		}
		template<class E>
		sglRef<E> reinterpret_ref_cast()
		{
			return sglRef<E>(std::reinterpret_pointer_cast<E>(this->_ptr));
		}



		T* operator-> () { return this->_ptr.get(); }
		const T* operator-> ()const { return this->_ptr.get(); }

		T& operator* () { return *this->_ptr; }
		const T& operator* ()const { return *this->_ptr; }

		operator bool()const { return this->_ptr.get() != nullptr; }

	public:
		template<class ... ARGS>
		static sglRef make(ARGS&& ... args)
		{
			sglRef ref;
			ref._ptr = std::make_shared<T>(args...);
			return ref;
		}
		template<class ... ARGS>
		void remake(ARGS&& ... args)
		{
			this->_ptr = std::make_shared<T>(args...);
		}
		void reset()
		{
			this->_ptr.reset();
		}
	private:
		std::shared_ptr<T> _ptr = nullptr;
	};
}

#endif //!__SGL_FUNDATION_REF__