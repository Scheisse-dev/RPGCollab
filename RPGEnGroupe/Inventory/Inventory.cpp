#include "Inventory.h"
#include <iostream>


Inventory::~Inventory()
{
	
}

void Inventory::RemoveItem(std::string _type, int _number)
{
	Gold _goldItem;
	PotionHeal _healItem;
	PotionMana _manaItem;
	if (_type == _healItem.Name() && healPotionCount != 0)
	{
		healPotionCount -= _number;
	}
	else if (_type == _manaItem.Name() && manaPotionCount != 0)
	{
		manaPotionCount -= _number;
	}
	else if (_type == _goldItem.Name() && goldCount != 0)
	{
		goldCount -= _number;
	}
	else
	{
		std::cout << "[Inventory] => nom de la ressource demande n'est pas valide ou stock egale a 0 !";
	}
}

void Inventory::AddItem(std::string _type, int _number)
{
	Gold _goldItem;
	PotionHeal _healItem;
	PotionMana _manaItem;
	if (_type == _healItem.Name())
	{
		healPotionCount += _number;
	}
	else if (_type == _manaItem.Name())
	{
		manaPotionCount += _number;
	}
	else if (_type == _goldItem.Name())
	{
		goldCount += _number;
	}
	else
	{
		std::cout << "[Inventory] => nom de la ressource demande n'est pas valide !";
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
