#include "Chest.h"
#include "../RPG/Game/RPG_Game.h"
#include "../Inventory/Inventory.h"
#include "../Item/RPG_Item.h"
#include <iostream>


#pragma region constructor
Chest::Chest()
{

}



Chest::~Chest()
{
	
}
#pragma endregion constructor
#pragma region methods


int Chest::ChooseNumberTypeOfItems(int _quantityOfItemMax)
{
	int rand = std::rand() % _quantityOfItemMax + 1;
	std::cout << rand << std::endl;
	return rand;
}

std::vector<int> Chest::ChooseWichItems(int _numberTypeOfItem)
{
	std::vector<int> _items = std::vector<int>();
	for (size_t i = 0; i < _numberTypeOfItem; i++)
	{
		int rand = std::rand() % QUANTITY_OF_ITEMS_TYPE + 1;
		_items.push_back(rand);
	}
	for (size_t i = 0; i < _numberTypeOfItem; i++)
	{
		std::cout << _items[i] << std::endl;
	}

	return _items ;
}

std::map<int, int> Chest::SetQuantityToItems(std::vector<int> _itemTypes)
{
	Gold _gold;
	 std::map<int, int> _quantity = std::map<int,int>();
	 size_t _size = _itemTypes.size();
	 for (size_t i = 0; i < _size; i++)
	 {
		 if (_itemTypes.data()[i] == _gold.ID() )
		 {
			 int _rand = std::rand() % 100 + 5;
			 _quantity.insert(std::pair(_itemTypes.data()[i], _rand));
		 }
		 else
		 {
			 int rand = std::rand() % 3 + 1;
			 _quantity.insert(std::pair(_itemTypes.data()[i], rand));
		 }
		 
	 }
	 return _quantity;
}

void Chest::SetDrop(int _quantityOfItemMax)
{
	SetQuantityToItems(ChooseWichItems(ChooseNumberTypeOfItems(_quantityOfItemMax)));
	

}

bool Chest::IsOpen()
{
	return isOpen;
}


#pragma endregion methods
