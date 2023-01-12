#include "PotionMana.h"

PotionMana::PotionMana(const char* _name, const int _value) : RPG_Item(_name, _value) {}

PotionMana::PotionMana(const PotionMana& _copy) {}

PotionMana::~PotionMana() {}

std::string PotionMana::Name() const
{
    return "Mana Potion";
}

int PotionMana::Value() const
{
    return MANA_POTION;
}
