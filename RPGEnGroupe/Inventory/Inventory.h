#pragma once
#include "../Object/Object.h"
#include "../UI/Image/RPG_Image.h"
#include "../Item/Potion/Heal/PotionHeal.h"
#include "../Item/Potion/Mana/PotionMana.h"
#include "../Item/Gold/Gold.h"

class Inventory : public Object
{
#pragma region f/p
private:
	int healPotionCount = START_HEALPOTION_COUNT;
	int manaPotionCount = START_MANAPOTION_COUNT;
	int goldCount = START_GOLD_COUNT;

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Inventory() = default;
	~Inventory() override;

#pragma endregion constructor/destructor
#pragma region methods
public:

	void RemoveItem(int _id, int _number);
	void AddItem(int _id, int _number);


	int HealPotionCount() const;
	int ManaPotionCount() const;
	int GoldCount() const;

#pragma endregion methods
#pragma region override
public:

#pragma endregion override
#pragma region operator
public:

#pragma endregion operator
};

