#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define SAMUS_SCALE 1.5f
#define GRAVITY 0.5f

class Animation;

class RPG_Samus : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	sf::Vector2f windowSize = sf::Vector2f();
	Animation* samusAnim = nullptr;
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
	//void Die();
public:
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
	void SetWindowSize(const sf::Vector2f& _size);
	void SetPosition(const sf::Vector2f& _position);
#pragma endregion override
	virtual void OnDraw(Window* _window) override;
};

