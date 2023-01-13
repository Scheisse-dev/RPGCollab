#include "Gold.h"

Gold::Gold(const char* _name, const int _value) : RPG_Item(_name, _value) {}

Gold::Gold(const Gold& _copy) : RPG_Item(_copy) {}

Gold::~Gold() {}

int Gold::ID() const
{
    return 3;
}

int Gold::Value() const
{
    return 1;
}

int Gold::Price() const
{
    return 0;
}

int Gold::Price() const
{
    return 0 ;
}
