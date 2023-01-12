#include "RPG_Mob.h"

RPG_Mob::RPG_Mob(const int _life, const int _damage, const char* _name) : RPG_Entity( _life, _damage, _name) {}

RPG_Mob::RPG_Mob(const RPG_Mob& _copy) : RPG_Entity(_copy) {}

RPG_Mob::~RPG_Mob() {}

int RPG_Mob::Life() const
{
    return MOB_MAX_LIFE;
}

int RPG_Mob::Damage() const
{
    return MOB_DAMAGE;
}

std::string RPG_Mob::Name() const
{
    return "mob";
}
