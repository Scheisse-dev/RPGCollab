#pragma once
#include "../../RPG_Item.h"
class PotionMana : public RPG_Item
{
#pragma region f/p
private:

#pragma endregion f/p
#pragma region constructor/destructor
public:
	PotionMana() = default;
	PotionMana(const char* _name, const int _value);
	PotionMana(const PotionMana& _copy);
	~PotionMana() override;
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

