#include "RPG_Player.h"

RPG_Player::RPG_Player(const int _life, const int _damage, const char* _name, const int _mana) : RPG_Entity(_life, _damage, _name)
{
	mana = _mana;
}

RPG_Player::RPG_Player(const RPG_Player& _copy) : RPG_Entity(_copy)
{
	mana = _copy.mana;
}

RPG_Player::~RPG_Player() {}

int RPG_Player::Mana() const
{
	return mana;
}

int RPG_Player::Life() const
{
	return PLAYER_MAX_LIFE;
}

int RPG_Player::Damage() const
{
	return PLAYER_DAMAGE;
}

std::string RPG_Player::Name() const
{
	return "player";
}
