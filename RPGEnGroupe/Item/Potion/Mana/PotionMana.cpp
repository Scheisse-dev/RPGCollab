#include "PotionMana.h"

PotionMana::PotionMana(const char* _name, const int _value) : RPG_Item(_name, _value) {}

PotionMana::PotionMana(const PotionMana& _copy) {}

PotionMana::~PotionMana() {}

int PotionMana::ID() const
{
    return 2;
}

int PotionMana::Value() const
{
    return MANA_POTION;
}
