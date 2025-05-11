#ifndef __SGL_UTILS_FUNCTION_TRAITS__
#define __SGL_UTILS_FUNCTION_TRAITS__


namespace sgl
{
	template<class T>
	struct sglFunctionTraits;
	template<class Ret,class ... Args>
	struct sglFunctionTraits<Ret(Args...)>
	{
		enum {arity = sizeof...(Args) };
		using return_t = Ret;
		using function_t = Ret(Args...);
		using stl_function_t = std::function<function_t>;
		using function_ptr_t = Ret(*)(Args...);
		template<unsigned Index>
		struct args
		{
			static_assert(Index < arity, "Out of Range");
			using type = std::tuple_element<Index, std::tuple<Args...>>::type;
		};
		using tuple_t = std::tuple<std::remove_cv_t<std::remove_reference_t<Args>>...>;
		using bare_tuple_t = std::tuple<std::remove_const_t<std::remove_reference_t<Args>>...>;



		using make_tuple_t = sglFunctionTraits<decltype(std::make_tuple<Args...>)>::return_t;
	};

	template<class Ret, class ... Args>
	struct sglFunctionTraits<Ret(*)(Args...)> : sglFunctionTraits<Ret(Args...)> {};
	template<class Ret, class ... Args>
	struct sglFunctionTraits<std::function<Ret(Args...)>> : sglFunctionTraits<Ret(Args...)> {};

#define SGL_FUNCTION_TRAITS(...)\
	template <typename Ret, typename Class, typename... Args>\
	struct sglFunctionTraits<Ret(Class::*)(Args...) __VA_ARGS__> : sglFunctionTraits<Ret(Args...)>{};

	SGL_FUNCTION_TRAITS()
	SGL_FUNCTION_TRAITS(const)
	SGL_FUNCTION_TRAITS(volatile)
	SGL_FUNCTION_TRAITS(const volatile)



	template<class Callable>
	struct sglFunctionTraits : sglFunctionTraits<decltype(&Callable::operator())> {};

	template<class ... Fx>
	struct sglFunctionsTraits
	{
		// TODO
		enum {count = sizeof...(Fx) };



		template<unsigned Index>
		using function_t = std::tuple_element<Index, std::tuple<Fx...>>::type;
		template<unsigned Index>
		using function_traits = sglFunctionTraits<function_t<Index>>;

	};
}

#endif //!__SGL_UTILS_FUNCTION_TRAITS__