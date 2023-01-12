#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"



class Animation;

class RPG_Samus : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;
	sf::Sprite* spriteSamus = nullptr;
	sf::Texture* textureSamus = nullptr;
	sf::Sprite* spritePalpatine = nullptr;
	sf::Texture* texturePalpatine = nullptr;
	sf::Sprite* spritePotionMana = nullptr;
	sf::Texture* texturePotionMana = nullptr;
	sf::Sprite* spritePotionHeal = nullptr;
	sf::Texture* texturePotionHeal = nullptr;
	sf::Vector2f windowSize = sf::Vector2f();
	Animation* samusAnimRight = nullptr;
	Animation* samusAnimLeft = nullptr;
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

