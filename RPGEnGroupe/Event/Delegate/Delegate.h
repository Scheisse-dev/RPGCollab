#pragma once
#include "../../Object/Object.h"

template<typename Res, typename... Args>
class Delegate
{
#pragma f/p
private:
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr;
	Object instance = nullptr;
#pragma endregion f/p
#pragma region constructor
public:
	Delegate(nullptr_t)
	{
		instance = nullptr;
		function = nullptr; 
	}
	Delegate(const Delegate& _copy)
	{
		instance = _copy.instance; 
		function = _copy.function;
	}
	template<typename Class>
	Delegate(Res(Class::* ptr)(Args...))
	{
		if constexpr (!std::is_base_of_v<Object, Class>)
			throw std::exception("Class must be inherited of Object");
		instance = _instance;
		function = reinterpret_cast<Function>(ptr);
	}
	~Delegate()
	{

	};
#pragma endregion constructor
#pragma region methods
public:
	template<typename Class>
	void SetDynamic(Class* _instance, Res(Class::* ptr) (Params...))
	{
		*this = Delegate(_instance, ptr);
	}

	void SetDynamic(nullptr_t)
	{
		*this = Delegate(nullptr);
	}
	Res Invoke(Params... _params)
	{
		if (instance == nullptr)
			throw std::exception("instance is nullptr");
		if (function == nullptr)
			throw std::exception("function is nullptr");
		return (instance->*function)(_params...);
	}
#pragma endregion methods
#pragma region operator
public:
	void operator=(const Delegate& other)
	{
		instance = instance.other;
		function = function.other;
	}
	void operator=(nullptr_t)
	{
		instance = nullptr; 
		function = nullptr;
	}
#pragma endregion operator

};
