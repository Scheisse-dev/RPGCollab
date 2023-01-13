#include "RPG_Samus.h"
#include "../../Time/Time.h"
#include "../../Event/Input/Input.h"
#include "../../UI/Image/RPG_Image.h"
#include "../../UI/Label/RPG_Label.h"
#include "../../Animation/Animation.h"
#include "../../Inventory/Inventory.h"
#include <iostream>
#include <string>

#pragma region constructor
RPG_Samus::RPG_Samus()
{
	Inventory inventory = Inventory();

#pragma region font
	font = new sf::Font();
	if (!font->loadFromFile("../Donnees/Fonts/Ubuntu-Title.ttf"))
		return;
#pragma endregion

#pragma region platforme
	Platforme1 = new RPG_Image(this, "../Donnees/Sol.png");
	Platforme2 = new RPG_Image(this, "../Donnees/Sol.png");
	Platforme3 = new RPG_Image(this, "../Donnees/Sol.png");
	Platforme4 = new RPG_Image(this, "../Donnees/Sol.png");

	Platforme1->SetOrigin(sf::Vector2f(0, 0));
	Platforme1->SetScale(sf::Vector2f(PLATFORME1_SCALE, PLATFORME1_SCALE));
	Platforme1->SetPosition(PLATFORME1_POSITION);

	Platforme2->SetOrigin(sf::Vector2f(0, 0));
	Platforme2->SetScale(sf::Vector2f(PLATFORME2_SCALE, PLATFORME2_SCALE));
	Platforme2->SetPosition(PLATFORME2_POSITION);

	Platforme3->SetOrigin(sf::Vector2f(0, 0));
	Platforme3->SetScale(sf::Vector2f(PLATFORME3_SCALE, PLATFORME3_SCALE));
	Platforme3->SetPosition(PLATFORME3_POSITION);

	Platforme4->SetOrigin(sf::Vector2f(0, 0));
	Platforme4->SetScale(sf::Vector2f(PLATFORME4_SCALE, PLATFORME4_SCALE));
	Platforme4->SetPosition(PLATFORME4_POSITION);
#pragma endregion

#pragma region samus
	Samus = new RPG_Image(this, "../Donnees/Samus/NoMove.png");

	Samus->SetOrigin(sf::Vector2f(0, 0));
	Samus->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
	Samus->SetPosition(SAMUS_POSITION);
#pragma endregion

#pragma region Potion Mana
	PotionMana = new RPG_Image(this, "../Donnees/Item/Potion_Mana.png");
	textMana = new RPG_Label(this, "../Donnees/Fonts/Ubuntu-Title.ttf");

	textMana->SetFont(*font);
	textMana->SetText(std::to_string(inventory.ManaPotionCount()).c_str());
	textMana->SetCharacterSize(SIZE_TEXT);
	textMana->SetColor(COLOR_TEXT);
	textMana->SetPosition(TEXT_MANA_POSITION);

	PotionMana->SetOrigin(sf::Vector2f(0, 0));
	PotionMana->SetScale(sf::Vector2f(POTION_MANA_SCALE, POTION_MANA_SCALE));
	PotionMana->SetPosition(POTION_MANA_POSITION);
#pragma endregion

#pragma region Potion Heal
	PotionHeal = new RPG_Image(this, "../Donnees/Item/Potion_Heal.png");
	textHeal = new RPG_Label(this, "../Donnees/Fonts/Ubuntu-Title.ttf");

	textHeal->SetFont(*font);
	textHeal->SetText(std::to_string(inventory.HealPotionCount()).c_str());
	textHeal->SetCharacterSize(SIZE_TEXT);
	textHeal->SetColor(COLOR_TEXT);
	textHeal->SetPosition(TEXT_HEAL_POSITION);

	PotionHeal->SetOrigin(sf::Vector2f(0, 0));
	PotionHeal->SetScale(sf::Vector2f(POTION_HEAL_SCALE, POTION_HEAL_SCALE));
	PotionHeal->SetPosition(POTION_HEAL_POSITION);
#pragma endregion

#pragma region display Rod Mana
	PotionManaRod = new RPG_Image(this, "../Donnees/Item/Rod_Mana.png");
	textManaRod = new RPG_Label(this, "../Donnees/Fonts/Ubuntu-Title.ttf");

	textManaRod->SetFont(*font);
	textManaRod->SetText("100");
	textManaRod->SetCharacterSize(SIZE_TEXT);
	textManaRod->SetColor(COLOR_TEXT);
	textManaRod->SetPosition(TEXT_MANA_ROD_POSITION);

	PotionManaRod->SetOrigin(sf::Vector2f(0, 0));
	PotionManaRod->SetScale(sf::Vector2f(POTION_MANA_ROD_SCALE, POTION_MANA_ROD_SCALE));
	PotionManaRod->SetPosition(POTION_MANA_ROD_POSITION);
#pragma endregion

#pragma region display Rod Heal
	PotionHealRod = new RPG_Image(this, "../Donnees/Item/Rod_Heal.png");
	textHealRod = new RPG_Label(this, "../Donnees/Fonts/Ubuntu-Title.ttf");

	textHealRod->SetFont(*font);
	textHealRod->SetText("100");
	textHealRod->SetCharacterSize(SIZE_TEXT);
	textHealRod->SetColor(COLOR_TEXT);
	textHealRod->SetPosition(TEXT_HEAL_ROD_POSITION);

	PotionHealRod->SetOrigin(sf::Vector2f(0, 0));
	PotionHealRod->SetScale(sf::Vector2f(POTION_HEAL_ROD_SCALE, POTION_HEAL_ROD_SCALE));
	PotionHealRod->SetPosition(POTION_HEAL_ROD_POSITION);
#pragma endregion

#pragma region Coin
	Coin = new RPG_Image(this, "../Donnees/Item/Coin.png");
	textCoin = new RPG_Label(this, "../Donnees/Fonts/Ubuntu-Title.ttf");

	textCoin->SetFont(*font);
	textCoin->SetText(("x" + std::to_string(inventory.GoldCount())).c_str());
	textCoin->SetCharacterSize(SIZE_TEXT);
	textCoin->SetColor(COLOR_TEXT);
	textCoin->SetPosition(TEXT_COIN_POSITION);

	Coin->SetOrigin(sf::Vector2f(0, 0));
	Coin->SetScale(sf::Vector2f(COIN_SCALE, COIN_SCALE));
	Coin->SetPosition(COIN_POSITION);
#pragma endregion

#pragma region Chest
	Chest = new RPG_Image(this, "../Donnees/chestClose.png");

	Chest->SetOrigin(sf::Vector2f(0, 0));
	Chest->SetScale(sf::Vector2f(CHEST_SCALE, CHEST_SCALE));
	Chest->SetPosition(CHEST_POSITION);
#pragma endregion

#pragma region Animation
	samusAnimRight = new Animation(Samus, "../Donnees/Samus/Run_Right_low.png", "../Donnees/Samus/Run_Right.png", SAMUS_ANIMATION_INITIAL_SPEED, SAMUS_ANIMATION_SPEED);
	samusAnimRight->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));

	samusAnimLeft = new Animation(Samus, "../Donnees/Samus/Run_Left_low.png", "../Donnees/Samus/Run_left.png", SAMUS_ANIMATION_INITIAL_SPEED, SAMUS_ANIMATION_SPEED);
	samusAnimLeft->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
#pragma endregion
}
RPG_Samus::~RPG_Samus()
{
	delete Platforme1;
	Platforme1 = nullptr;

	delete Platforme2;
	Platforme2 = nullptr;

	delete Platforme3;
	Platforme3 = nullptr;

	delete Platforme4;
	Platforme4 = nullptr;

	delete Samus;
	Samus = nullptr;

	delete PotionHeal;
	PotionHeal = nullptr;

	delete PotionMana;
	PotionMana = nullptr;

	delete PotionHealRod;
	PotionHealRod = nullptr;

	delete PotionManaRod;
	PotionManaRod = nullptr;

	delete Chest;
	Chest = nullptr;
}
#pragma endregion

#pragma region override
//void RPG_Samus::Die()
//{
//	if (isDead)
//		return;
//	isDead = true;
//	onDie.Invoke();
//}
void RPG_Samus::OnUpdate()
{
#pragma region touche move
	if (Input::IsKeyDown(sf::Keyboard::D))
	{
		Samus->SetPosition(Samus->GetPosition() + sf::Vector2f(SAMUS_SPEED, 0));
		samusAnimRight->AnimationUpdate(2);
	}
	if (Input::IsKeyDown(sf::Keyboard::Q))
	{
		Samus->SetPosition(Samus->GetPosition() + sf::Vector2f(-SAMUS_SPEED, 0));
		samusAnimLeft->AnimationUpdate(2);
	}
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		Samus->SetPosition(Samus->GetPosition() - sf::Vector2f(0, JUMP_FORCE));
	}
#pragma endregion

#pragma region touche Item
	if (Input::IsKeyDown(sf::Keyboard::A))
	{
		std::cout << "Heal !" << std::endl;
	}
	if (Input::IsKeyDown(sf::Keyboard::E))
	{
		std::cout << "Mana !" << std::endl;
	}
	if (Samus->GetGlobalBounds().intersects(Chest->GetGlobalBounds()) && Input::IsKeyDown(sf::Keyboard::F))
	{
		std::cout << "Open chest !" << std::endl;
	}
	if (Input::IsKeyDown(sf::Keyboard::B))
	{
		std::cout << "Shop !" << std::endl;
	}
#pragma endregion

#pragma region set position sol 
	if (Samus->GetPosition().y <= HEIGHT - 140)
	{
		Samus->SetPosition(Samus->GetPosition() + sf::Vector2f(0, 0.05f));
	}
#pragma endregion

#pragma region collision
	/*if (spriteSamus->getPosition().y <= 50)
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + PLATFORME1_POSITION);
	}*/
#pragma endregion
}
void RPG_Samus::SetWindowSize(const sf::Vector2f& _size)
{
	windowSize = _size;
}
void RPG_Samus::OnDraw()
{
	Samus->Draw(this);
}
#pragma endregion