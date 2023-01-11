#pragma once
#include "../RPG/DataBase/DataBase.h"
#include <string>

class Object
{
#pragma region constructor/destructor
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual std::string ToString() = 0;
#pragma endregion methods
};

