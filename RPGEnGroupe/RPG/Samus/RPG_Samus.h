#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

class Animation;

class RPG_Samus : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;

	sf::Font* font = nullptr;

	sf::Sprite* spritePlatforme1 = nullptr;
	sf::Texture* texturePlatforme1 = nullptr;
	sf::Sprite* spritePlatforme2 = nullptr;
	sf::Texture* texturePlatforme2 = nullptr;
	sf::Sprite* spritePlatforme3 = nullptr;
	sf::Texture* texturePlatforme3 = nullptr;
	sf::Sprite* spritePlatforme4 = nullptr;
	sf::Texture* texturePlatforme4 = nullptr;

	sf::Sprite* spriteSamus = nullptr;
	sf::Texture* textureSamus = nullptr;

	sf::Text* textMana = nullptr;
	sf::Sprite* spritePotionMana = nullptr;
	sf::Texture* texturePotionMana = nullptr;

	sf::Text* textHeal = nullptr;
	sf::Sprite* spritePotionHeal = nullptr;
	sf::Texture* texturePotionHeal = nullptr;

	sf::Text* textCoin = nullptr;
	sf::Sprite* spriteCoin = nullptr;
	sf::Texture* textureCoin = nullptr;

	sf::Sprite* spriteChest = nullptr;
	sf::Texture* textureChest = nullptr;

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

