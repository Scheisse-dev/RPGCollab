#pragma once
#include "../RPG_Entity.h"
class RPG_Mob : public RPG_Entity
{
#pragma region f/p
private:

#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Mob() = default;
	RPG_Mob(const int _life, const int _damage, const char* _name);
	RPG_Mob(const RPG_Mob& _copy);
	~RPG_Mob() override;
#pragma endregion constructor/destructor
#pragma region methods
public:

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

	// Inherited via RPG_Entity
};

