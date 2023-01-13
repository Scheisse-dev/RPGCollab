#pragma once
#include "../../GameObject/Manager/RPG_GameObjectManager.h"
#include <string>
class RPG_Entity : public RPG_GameObjectManager
{
#pragma region f/p
private:
	int life = 0;
	int damage = 0;
	std::string name = "";

	
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Entity() = default;
	RPG_Entity(const int _life, const int _damage, const char* _name);
	RPG_Entity(const RPG_Entity& _copy);
	virtual ~RPG_Entity() override;

#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual int Life() const = 0 ;
	virtual std::string Name() const = 0;


#pragma endregion methods

};

