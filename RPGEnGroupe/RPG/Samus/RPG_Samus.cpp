#include "RPG_Samus.h"
#include "../../Time/Time.h"
#include "../../Event/Input/Input.h"
#include "../../UI/Image/RPG_Image.h"
#include "../../Animation/Animation.h"
#include "../../Inventory/Inventory.h"
#include <iostream>

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
	spritePlatforme1 = new sf::Sprite();
	texturePlatforme1 = new sf::Texture();
	spritePlatforme2 = new sf::Sprite();
	texturePlatforme2 = new sf::Texture();
	spritePlatforme3 = new sf::Sprite();
	texturePlatforme3 = new sf::Texture();
	spritePlatforme4 = new sf::Sprite();
	texturePlatforme4 = new sf::Texture();

	if (texturePlatforme1->loadFromFile("../Donnees/Sol.png"))
	{
		spritePlatforme1->setTexture(*texturePlatforme1);
	}
	if (texturePlatforme2->loadFromFile("../Donnees/Sol.png"))
	{
		spritePlatforme2->setTexture(*texturePlatforme2);
	}
	if (texturePlatforme3->loadFromFile("../Donnees/Sol.png"))
	{
		spritePlatforme3->setTexture(*texturePlatforme1);
	}
	if (texturePlatforme4->loadFromFile("../Donnees/Sol.png"))
	{
		spritePlatforme4->setTexture(*texturePlatforme1);
	}

	spritePlatforme1->setOrigin(sf::Vector2f(0, 0));
	spritePlatforme1->setScale(sf::Vector2f(PLATFORME1_SCALE, PLATFORME1_SCALE));
	spritePlatforme1->setPosition(PLATFORME1_POSITION);
	drawablePlatforme1 = spritePlatforme1;

	spritePlatforme2->setOrigin(sf::Vector2f(0, 0));
	spritePlatforme2->setScale(sf::Vector2f(PLATFORME2_SCALE, PLATFORME2_SCALE));
	spritePlatforme2->setPosition(PLATFORME2_POSITION);
	drawablePlatforme2 = spritePlatforme2;

	spritePlatforme3->setOrigin(sf::Vector2f(0, 0));
	spritePlatforme3->setScale(sf::Vector2f(PLATFORME3_SCALE, PLATFORME3_SCALE));
	spritePlatforme3->setPosition(PLATFORME3_POSITION);
	drawablePlatforme3 = spritePlatforme3;

	spritePlatforme4->setOrigin(sf::Vector2f(0, 0));
	spritePlatforme4->setScale(sf::Vector2f(PLATFORME4_SCALE, PLATFORME4_SCALE));
	spritePlatforme4->setPosition(PLATFORME4_POSITION);
	drawablePlatforme4 = spritePlatforme4;
#pragma endregion

#pragma region samus
	spriteSamus = new sf::Sprite();
	textureSamus = new sf::Texture();

	if (textureSamus->loadFromFile("../Donnees/Samus/NoMove.png"))
	{
		spriteSamus->setTexture(*textureSamus);
	}

	spriteSamus->setOrigin(sf::Vector2f(0, 0));
	spriteSamus->setScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
	spriteSamus->setPosition(SAMUS_POSITION);
	drawableSamus = spriteSamus;
#pragma endregion

#pragma region Potion Mana
	spritePotionMana = new sf::Sprite();
	texturePotionMana = new sf::Texture();
	textMana = new sf::Text();

	if (texturePotionMana->loadFromFile("../Donnees/Item/Potion_Mana.png"))
	{
		spritePotionMana->setTexture(*texturePotionMana);
	}

	textMana->setFont(*font);
	textMana->setString("x" + std::to_string(inventory.ManaPotionCount()));
	textMana->setCharacterSize(SIZE_TEXT);
	textMana->setFillColor(COLOR_TEXT);
	textMana->setPosition(TEXT_MANA_POSITION);
	drawablePotionManaText = textMana;

	spritePotionMana->setOrigin(sf::Vector2f(0, 0));
	spritePotionMana->setScale(sf::Vector2f(POTION_MANA_SCALE, POTION_MANA_SCALE));
	spritePotionMana->setPosition(POTION_MANA_POSITION);
	drawablePotionMana = spritePotionMana;
#pragma endregion

#pragma region Potion Heal
	spritePotionHeal = new sf::Sprite();
	texturePotionHeal = new sf::Texture();
	textHeal = new sf::Text();

	if (texturePotionHeal->loadFromFile("../Donnees/Item/Potion_Heal.png"))
	{
		spritePotionHeal->setTexture(*texturePotionHeal);
	}

	textHeal->setFont(*font);
	textHeal->setString("x" + std::to_string(inventory.HealPotionCount()));
	textHeal->setCharacterSize(SIZE_TEXT);
	textHeal->setFillColor(COLOR_TEXT);
	textHeal->setPosition(TEXT_HEAL_POSITION);
	drawablePotionHealText = textHeal;

	spritePotionHeal->setOrigin(sf::Vector2f(0, 0));
	spritePotionHeal->setScale(sf::Vector2f(POTION_HEAL_SCALE, POTION_HEAL_SCALE));
	spritePotionHeal->setPosition(POTION_HEAL_POSITION);
	drawablePotionHeal = spritePotionHeal;
#pragma endregion

#pragma region Coin
	spriteCoin = new sf::Sprite();
	textureCoin = new sf::Texture();
	textCoin = new sf::Text();

	if (textureCoin->loadFromFile("../Donnees/Item/Coin.png"))
	{
		spriteCoin->setTexture(*textureCoin);
	}

	textCoin->setFont(*font);
	textCoin->setString("x" + std::to_string(inventory.GoldCount()));
	textCoin->setCharacterSize(SIZE_TEXT);
	textCoin->setFillColor(COLOR_TEXT);
	textCoin->setPosition(TEXT_COIN_POSITION);
	drawableCoinText = textCoin;

	spriteCoin->setOrigin(sf::Vector2f(0, 0));
	spriteCoin->setScale(sf::Vector2f(COIN_SCALE, COIN_SCALE));
	spriteCoin->setPosition(COIN_POSITION);
	drawableCoin = spriteCoin;
#pragma endregion

#pragma region Chest
	spriteChest = new sf::Sprite();
	textureChest = new sf::Texture();

	if (textureChest->loadFromFile("../Donnees/chestClose.png"))
	{
		spriteChest->setTexture(*textureChest);
	}

	spriteChest->setOrigin(sf::Vector2f(0, 0));
	spriteChest->setScale(sf::Vector2f(CHEST_SCALE, CHEST_SCALE));
	spriteChest->setPosition(CHEST_POSITION);
	drawableChest = spriteChest;
#pragma endregion

#pragma region Animation
	samusAnimRight = new Animation(spriteSamus, "../Donnees/Samus/Run_Right_low.png", "../Donnees/Samus/Run_Right.png", SAMUS_ANIMATION_INITIAL_SPEED, SAMUS_ANIMATION_SPEED);
	samusAnimRight->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));

	samusAnimLeft = new Animation(spriteSamus, "../Donnees/Samus/Run_Left_low.png", "../Donnees/Samus/Run_left.png", SAMUS_ANIMATION_INITIAL_SPEED, SAMUS_ANIMATION_SPEED);
	samusAnimLeft->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
#pragma endregion
}
RPG_Samus::~RPG_Samus()
{
	delete spritePlatforme1;
	spritePlatforme1 = nullptr;
	delete texturePlatforme1;
	texturePlatforme1 = nullptr;

	delete spritePlatforme2;
	spritePlatforme2 = nullptr;
	delete texturePlatforme2;
	texturePlatforme2 = nullptr;

	delete spritePlatforme3;
	spritePlatforme3 = nullptr;
	delete texturePlatforme3;
	texturePlatforme3 = nullptr;

	delete spritePlatforme4;
	spritePlatforme4 = nullptr;
	delete texturePlatforme4;
	texturePlatforme4 = nullptr;

	delete spriteSamus;
	spriteSamus = nullptr;
	delete textureSamus;
	textureSamus = nullptr;

	delete spritePotionHeal;
	spritePotionHeal = nullptr;
	delete texturePotionHeal;
	texturePotionHeal = nullptr;

	delete spritePotionMana;
	spritePotionMana = nullptr;
	delete texturePotionMana;
	texturePotionMana = nullptr;

	delete spriteChest;
	spriteChest = nullptr;
	delete textureChest;
	textureChest = nullptr;
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
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(SAMUS_SPEED, 0));
		samusAnimRight->AnimationUpdate(2);
	}
	if (Input::IsKeyDown(sf::Keyboard::Q))
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(-SAMUS_SPEED, 0));
		samusAnimLeft->AnimationUpdate(2);
	}
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		spriteSamus->setPosition(spriteSamus->getPosition() - sf::Vector2f(0, JUMP_FORCE));
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
	if (Input::IsKeyDown(sf::Keyboard::F))
	{
		std::cout << "Open chest !" << std::endl;
	}
	if (Input::IsKeyDown(sf::Keyboard::B))
	{
		std::cout << "Shop !" << std::endl;
	}
#pragma endregion

#pragma region set position sol 
	if (spriteSamus->getPosition().y <= HEIGHT - 140)
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(0, 0.05f));
	}
#pragma endregion
}
sf::FloatRect RPG_Samus::GetGlobalBounds() const
{
	return spriteSamus->getGlobalBounds();
}
sf::Vector2f RPG_Samus::Position() const
{
	return spriteSamus->getPosition();
}
void RPG_Samus::SetWindowSize(const sf::Vector2f& _size)
{
	windowSize = _size;
}
void RPG_Samus::SetPosition(const sf::Vector2f& _position)
{
	if (spriteSamus == nullptr) return;
	spriteSamus->setPosition(_position);
}
void RPG_Samus::OnDraw(Window* _window)
{
	GameObject::OnDraw(_window);
}
#pragma endregion

