#include "Inventory.h"
#include <iostream>


Inventory::~Inventory()
{
	
}

void Inventory::RemoveItem(int _id, int _number)
{
	Gold _goldItem;
	PotionHeal _healItem;
	PotionMana _manaItem;
	if (_id == _healItem.ID() && healPotionCount != 0)
	{
		healPotionCount -= _number;
	}
	else if (_id == _manaItem.ID() && manaPotionCount != 0)
	{
		manaPotionCount -= _number;
	}
	else if (_id == _goldItem.ID() && goldCount != 0)
	{
		goldCount -= _number;
	}
	else
	{
		std::cout << "[Inventory] => id de la ressource demande n'est pas valide ou stock egale a 0 !";
	}
}

void Inventory::AddItem(int _id, int _number)
{
	Gold _goldItem;
	PotionHeal _healItem;
	PotionMana _manaItem;
	if (_id == _healItem.ID())
	{
		healPotionCount += _number;
	}
	else if (_id == _manaItem.ID())
	{
		manaPotionCount += _number;
	}
	else if (_id == _goldItem.ID())
	{
		goldCount += _number;
	}
	else
	{
		std::cout << "[Inventory] => id de la ressource demande n'est pas valide !";
	}
}

int Inventory::HealPotionCount() const
{
	return healPotionCount;
}

int Inventory::ManaPotionCount() const
{
	return manaPotionCount;
}

int Inventory::GoldCount() const
{
	return goldCount;
}
