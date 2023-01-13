#include "PotionHeal.h"

PotionHeal::PotionHeal(const char* _name, const int _value) : RPG_Item(_name, _value) {}

PotionHeal::PotionHeal(const PotionHeal& _copy) : RPG_Item( _copy) {}

PotionHeal::~PotionHeal()
{
}

int PotionHeal::ID() const
{
    return 1;
}

int PotionHeal::Value() const
{
    return HEAL_POTION;
}
