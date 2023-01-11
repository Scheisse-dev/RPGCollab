#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define SAMUS_SCALE 0.05f
#define GRAVITY 0.5f

class RPG_Samus : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	sf::Vector2f windowSize = sf::Vector2f();
public:
	Delegate<void> onDie = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Samus();
	virtual ~RPG_Samus() override;
#pragma endregion constructor/destructor
#pragma region override
private:
	void Die();
public:
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
	void SetWindowSize(const sf::Vector2f& _size);
#pragma endregion override
};

