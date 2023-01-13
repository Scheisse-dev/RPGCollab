#pragma once
#include "../../RPG_Item.h"
class PotionHeal : public RPG_Item
{
#pragma region f/p
private:

#pragma endregion f/p
#pragma region constructor/destructor
public:
	PotionHeal() = default;
	PotionHeal(const char* _name, const int _value);
	PotionHeal(const PotionHeal& _copy);
	~PotionHeal() override;

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

};

