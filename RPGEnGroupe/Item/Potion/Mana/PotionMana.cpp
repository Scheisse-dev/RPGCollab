#include "PotionMana.h"

PotionMana::PotionMana(int _id, const int _value) : RPG_Item(_id, _value) {}

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

int PotionMana::Price() const
{
    return 25;
}
