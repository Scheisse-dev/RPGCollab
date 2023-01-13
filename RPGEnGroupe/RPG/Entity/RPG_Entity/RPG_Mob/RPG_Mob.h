#pragma once
#include "../RPG_Entity.h"

class RPG_Player;
class Animation;

class RPG_Mob : public RPG_Entity
{
#pragma region f/p
private:

	sf::Clock* patern = nullptr;
	sf::Clock* speed = nullptr;
	sf::Sprite* sprite = nullptr; 
	sf::Texture* texture = nullptr;
	sf::Vector2f position;
	sf::Clock clock = sf::Clock();
	float scale = 0; 
	const char* path = "";
	const char* name = "";
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Mob() = default;
	RPG_Mob(const int _life, const char* _name, const char* _path, const float _scale, sf::Sprite* _sprite, sf::Vector2f _position);
	RPG_Mob(const RPG_Mob& _copy);
	~RPG_Mob() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetPosition();
	void SetScale(); 
	void SetTexture();
	void Draw(sf::RenderWindow _owner); 
	void Move();
	void SetAnimation(); 
#pragma endregion methods
#pragma region override
public:
	virtual int Life() const override;
	virtual std::string Name() const override;

#pragma endregion override
};

