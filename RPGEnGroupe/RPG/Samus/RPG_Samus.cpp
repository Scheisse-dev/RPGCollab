#include "RPG_Samus.h"
#include "../../Time/Time.h"
#include "../../Event/Input/Input.h"
#include "../../UI/Image/RPG_Image.h"
#include "../../Animation/Animation.h"

#pragma region constructor
RPG_Samus::RPG_Samus()
{
	//Samus
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

	//Palpatine
	spritePalpatine = new sf::Sprite();
	texturePalpatine = new sf::Texture();

	if (texturePalpatine->loadFromFile("../Donnees/Palpatine/Dab.png"))
	{
		spritePalpatine->setTexture(*texturePalpatine);
	}

	spritePalpatine->setOrigin(sf::Vector2f(0, 0));
	spritePalpatine->setScale(sf::Vector2f(PALPATINE_SCALE, PALPATINE_SCALE));
	spritePalpatine->setPosition(PALPATINE_POSITION);
	drawablePalpatine = spritePalpatine;

	//Potion Mana
	spritePotionMana = new sf::Sprite();
	texturePotionMana = new sf::Texture();

	if (texturePotionMana->loadFromFile("../Donnees/Item/Potion_Mana.png"))
	{
		spritePotionMana->setTexture(*texturePotionMana);
	}

	spritePotionMana->setOrigin(sf::Vector2f(0, 0));
	spritePotionMana->setScale(sf::Vector2f(POTION_MANA_SCALE, POTION_MANA_SCALE));
	spritePotionMana->setPosition(POTION_MANA_POSITION);
	drawablePotionMana = spritePotionMana;

	//Potion Heal
	spritePotionHeal = new sf::Sprite();
	texturePotionHeal = new sf::Texture();

	if (texturePotionHeal->loadFromFile("../Donnees/Item/Potion_Heal.png"))
	{
		spritePotionHeal->setTexture(*texturePotionHeal);
	}

	spritePotionHeal->setOrigin(sf::Vector2f(0, 0));
	spritePotionHeal->setScale(sf::Vector2f(POTION_HEAL_SCALE, POTION_HEAL_SCALE));
	spritePotionHeal->setPosition(POTION_HEAL_POSITION);
	drawablePotionHeal = spritePotionHeal;

	//animation
	samusAnimRight = new Animation(spriteSamus, "../Donnees/Samus/Run_Right_low.png", "../Donnees/Samus/Run_Right.png", SAMUS_ANIMATION_INITIAL_SPEED, SAMUS_ANIMATION_SPEED);
	samusAnimRight->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));

	samusAnimLeft = new Animation(spriteSamus, "../Donnees/Samus/Run_Left_low.png", "../Donnees/Samus/Run_left.png", SAMUS_ANIMATION_INITIAL_SPEED, SAMUS_ANIMATION_SPEED);
	samusAnimLeft->SetScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
}
RPG_Samus::~RPG_Samus()
{
	delete spriteSamus;
	spriteSamus = nullptr;
	delete textureSamus;
	textureSamus = nullptr;

	delete spritePalpatine;
	spritePalpatine = nullptr;
	delete texturePalpatine;
	texturePalpatine = nullptr;

	delete spritePotionHeal;
	spritePotionHeal = nullptr;
	delete texturePotionHeal;
	texturePotionHeal = nullptr;

	delete spritePotionMana;
	spritePotionMana = nullptr;
	delete texturePotionMana;
	texturePotionMana = nullptr;
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
	/*if (isDead)
		return;*/
	textureSamus->loadFromFile("../Donnees/Samus/NoMove.png");
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
	//position au sol
	if (spriteSamus->getPosition().y <= HEIGHT - 125)
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(0, 0.05f));
	}
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

