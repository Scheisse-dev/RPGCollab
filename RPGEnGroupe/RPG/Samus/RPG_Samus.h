#pragma once
#include "../../Window/Window.h"
#include "../../Event/Delegate/Delegate.h"

class Animation;
class RPG_Image;
class RPG_Label;

class RPG_Samus : public Window
{
#pragma region f/p
private:
	bool isDead = false;

	sf::Font* font = nullptr;

	RPG_Image* Platforme1 = nullptr;
	RPG_Image* Platforme2 = nullptr;
	RPG_Image* Platforme3 = nullptr;
	RPG_Image* Platforme4 = nullptr;

	RPG_Image* Samus = nullptr;

	RPG_Label* textMana = nullptr;
	RPG_Label* textManaRod = nullptr;
	RPG_Image* PotionMana = nullptr;
	RPG_Image* PotionManaRod = nullptr;

	RPG_Label* textHeal = nullptr;
	RPG_Label* textHealRod = nullptr;
	RPG_Image* PotionHeal = nullptr;
	RPG_Image* PotionHealRod = nullptr;

	RPG_Label* textCoin = nullptr;
	RPG_Image* Coin = nullptr;

	RPG_Image* Chest = nullptr;

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
	void SetWindowSize(const sf::Vector2f& _size);
	void SetPosition(const sf::Vector2f& _position);
	virtual void OnDraw() override;
#pragma endregion override
};

