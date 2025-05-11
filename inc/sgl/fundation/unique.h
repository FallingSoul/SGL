#ifndef __SGL_FUNDATION_UNIQUE__
#define __SGL_FUNDATION_UNIQUE__

#include <memory>

namespace sgl
{
	template<class T>
	class sglUnique
	{
	public:
		sglUnique(const sglUnique&) = default;
		sglUnique(sglUnique&&) = default;
		sglUnique() = default;
		~sglUnique() = default;
		sglUnique& operator= (const sglUnique&) = default;
	public:
		explicit sglUnique(T* t)
			:_ptr(t)
		{ }
		explicit sglUnique(std::unique_ptr<T>&& ptr)
			:_ptr(ptr)
		{ }
		template<class E>
		sglUnique(const sglUnique<E>&& unique)
			:_ptr(std::move(unique._ptr))
		{}

		T* operator-> () { return this->_ptr.get(); }
		const T* operator-> ()const { return this->_ptr.get(); }

		T& operator* () { return *this->_ptr; }
		const T& operator* ()const { return *this->_ptr; }

		operator bool()const { return this->_ptr.get() != nullptr; }

		T* get() { return this->_ptr.get(); }
		const T* get()const { return this->_ptr.get(); }
	public:
		template<class ... ARGS>
		static sglUnique make(ARGS&& ... args)
		{
			return sglUnique(std::make_unique<T>(args...));
		}
		template<class ... ARGS>
		void remake(ARGS&& ... args)
		{
			this->_ptr = std::make_unique<T>(args...);
		}
		void reset()
		{
			this->_ptr.reset();
		}

	private:
		std::unique_ptr<T> _ptr = nullptr;
	};
}


#endif //!__SGL_FUNDATION_UNIQUE__