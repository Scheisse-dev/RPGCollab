#pragma once
#include "../Object/Object.h"
class RPG_Item : public Object
{
#pragma region f/p
private:
	std::string name = "";
	int value = 0;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Item() = default;
	RPG_Item(const char* _name, const int _value);
	RPG_Item(const RPG_Item& _copy);
	virtual ~RPG_Item() override;

#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual std::string Name() const = 0;
	virtual int Value() const = 0;
#pragma endregion methods
#pragma region override
public:

#pragma endregion override
#pragma region operator
public:

#pragma endregion operator
};

