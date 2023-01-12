#pragma once
#include "../RPG_Entity.h"
class RPG_Player : public RPG_Entity
{
#pragma region f/p
private:
	int mana = 100;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Player() = default;
	RPG_Player(const int _life, const int _damage, const char* _name, const int _mana);
	RPG_Player(const RPG_Player& _copy);
	~RPG_Player() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	int Mana() const;
#pragma endregion methods
#pragma region override
public:
	virtual int Life() const override;
	virtual int Damage() const override;
	virtual std::string Name() const override;

#pragma endregion override
#pragma region operator
public:

#pragma endregion operator

};

