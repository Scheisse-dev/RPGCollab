#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class Chest : public Object
{
#pragma region f/p
private:
	

protected :
	bool isOpen = false;

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Chest();
	~Chest() override; 
#pragma endregion constructor/destructor
#pragma region methods
public:

	int ChooseNumberTypeOfItems(int _quantityOfItemMax);
	std::vector<int> ChooseWichItems(int _numberTypeOfItem);
	std::map<int, int> SetQuantityToItems(std::vector<int> _itemTypes);
	void SetDrop(int _quantityOfItemMax);
	bool IsOpen();

#pragma endregion methods


};

