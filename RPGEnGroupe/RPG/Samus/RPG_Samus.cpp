#include "RPG_Samus.h"
#include "../../Time/Time.h"
#include "../../Event/Input/Input.h"
#include "../../UI/Image/RPG_Image.h"
#include "../../Animation/Animation.h"

#pragma region constructor
RPG_Samus::RPG_Samus()
{
	spriteSamus = new sf::Sprite();
	textureSamus = new sf::Texture();
	spritePalpatine = new sf::Sprite();
	texturePalpatine = new sf::Texture();

	if (textureSamus->loadFromFile("../Donnees/Samus/NoMove.png"))
	{
		spriteSamus->setTexture(*textureSamus);
	}
	if (texturePalpatine->loadFromFile("../Donnees/Palpatine/Dab.png"))
	{
		spritePalpatine->setTexture(*texturePalpatine);
	}

	spriteSamus->setOrigin(sf::Vector2f(0, 0));
	spriteSamus->setScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
	spriteSamus->setPosition(SAMUS_POSITION);
	drawableSamus = spriteSamus;

	spritePalpatine->setOrigin(sf::Vector2f(0, 0));
	spritePalpatine->setScale(sf::Vector2f(PALPATINE_SCALE, PALPATINE_SCALE));
	spritePalpatine->setPosition(PALPATINE_POSITION);
	drawablePalpatine = spritePalpatine;

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
	if (Input::IsKeyDown(sf::Keyboard::D))
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(40.0f, 0));
		samusAnimRight->AnimationUpdate(2);
	}
	if (Input::IsKeyDown(sf::Keyboard::Q))
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(-40.0f, 0));
		samusAnimLeft->AnimationUpdate(2);
	}
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		spriteSamus->setPosition(spriteSamus->getPosition() - sf::Vector2f(0, JUMP_FORCE));
	}
	if (spriteSamus->getPosition().y <= HEIGHT - 125)
	{
		spriteSamus->setPosition(spriteSamus->getPosition() + sf::Vector2f(0, 0.05f));
	}
	if (Input::IsKeyUp(sf::Keyboard::D) || Input::IsKeyUp(sf::Keyboard::Q))
	{
		textureSamus->loadFromFile("../Donnees/Samus/NoMove.png");
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

