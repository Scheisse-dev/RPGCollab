#include "Shop.h"
#include "../Inventory/Inventory.h"

Shop::~Shop()
{
}

void Shop::SellItem(const int _id)
{
	PotionHeal _healPotion;
	PotionMana _manaPotion;
	Inventory _inventory;
	bool _healBool = _healPotion.ID() == _id && _inventory.GoldCount() >= _healPotion.Price();
	bool _manaBool = _manaPotion.ID() == _id && _inventory.GoldCount() >= _manaPotion.Price();
	if (_healBool)
	{
		_inventory.AddItem(_id, 1);
		_inventory.RemoveItem(3, _healPotion.Price());
	}
	if (_healBool)
	{
		_inventory.AddItem(_id, 2);
		_inventory.RemoveItem(3, _manaPotion.Price());
	}
}
