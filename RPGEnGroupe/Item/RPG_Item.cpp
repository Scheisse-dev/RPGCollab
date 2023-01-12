#include "RPG_Item.h"

RPG_Item::RPG_Item(const char* _name, const int _value)
{
	name = _name;
	value = _value;
}

RPG_Item::RPG_Item(const RPG_Item& _copy)
{
	name = _copy.name;
	value = _copy.value;
}

RPG_Item::~RPG_Item() {}
