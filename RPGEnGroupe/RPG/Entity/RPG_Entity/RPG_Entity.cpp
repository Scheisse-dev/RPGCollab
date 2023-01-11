#include "RPG_Entity.h"

RPG_Entity::RPG_Entity(const int _life, const int _damage, const char* _name)
{
	life = _life;
	damage = _damage;
	name = _name;
}

RPG_Entity::RPG_Entity(const RPG_Entity& _copy)
{
	life = _copy.life;
	damage = _copy.damage;
	name = _copy.name;
}

RPG_Entity::~RPG_Entity() {}

int RPG_Entity::Life() const
{
	return life;
}

int RPG_Entity::Damage() const
{
	return damage;
}

std::string RPG_Entity::Name() const
{
	return name;
}
