#include "Gold.h"

Gold::Gold(const char* _name, const int _value) : RPG_Item(_name, _value) {}

Gold::Gold(const Gold& _copy) : RPG_Item(_copy) {}

Gold::~Gold() {}

std::string Gold::Name() const
{
    return "One Coin";
}

int Gold::Value() const
{
    return 1;
}
