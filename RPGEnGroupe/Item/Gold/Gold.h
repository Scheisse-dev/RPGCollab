#pragma once
#include "../RPG_Item.h"
class Gold : public RPG_Item
{
#pragma region f/p
private:

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Gold() = default;
	Gold(const char* _name, const int _value);
	Gold(const Gold& _copy);
	~Gold() override;
#pragma endregion constructor/destructor
#pragma region methods
public:

#pragma endregion methods
#pragma region override
public:
	virtual int ID() const override;
	virtual int Value() const override;

#pragma endregion override
#pragma region operator
public:

#pragma endregion operator



	// Inherited via RPG_Item
	virtual int Price() const override;

};

