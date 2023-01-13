#include "RPG_Entity.h"

RPG_Entity::RPG_Entity(const int _life, const char* _name)
{
	life = _life;
	name = _name;
}

RPG_Entity::RPG_Entity(const RPG_Entity& _copy)
{
	life = _copy.life;
	name = _copy.name;
}

RPG_Entity::~RPG_Entity() {}
