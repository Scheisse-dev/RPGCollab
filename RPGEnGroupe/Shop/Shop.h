#pragma once
#include "../Object/Object.h"
#include "../Item/Potion/Heal/PotionHeal.h"
#include "../Item/Potion/Mana/PotionMana.h"
#include "../Item/RPG_Item.h"
class Shop : public Object
{
#pragma region f/p
private:
	int slot = 0;

#pragma endregion f/p
public:
	Shop() = default;
	~Shop() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SellItem(const int _id);
#pragma endregion methods
#pragma region override
public:

#pragma endregion override
#pragma region operator
public:
	
#pragma endregion operator
};

