#include "PotionHeal.h"

PotionHeal::PotionHeal(int _id, const int _value) : RPG_Item(_id, _value) {}

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

int PotionHeal::Price() const
{
    return 20;
}
