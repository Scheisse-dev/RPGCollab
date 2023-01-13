#include "RPG_Item.h"

RPG_Item::RPG_Item(int _id, const int _value)
{
	id = _id;
	value = _value;
}

RPG_Item::RPG_Item(const RPG_Item& _copy)
{
	id = _copy.id;
	value = _copy.value;
}

RPG_Item::~RPG_Item() {}
