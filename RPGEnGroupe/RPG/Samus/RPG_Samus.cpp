#include "RPG_Samus.h"
#include "../../Time/Time.h"
#include "../../Event/Input/Input.h"
#include "../../UI/Image/RPG_Image.h"

#pragma region constructor
RPG_Samus::RPG_Samus()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (texture->loadFromFile("../Donnees/Samus/NoMove.png"))
	{
		sprite->setTexture(*texture);
	}
	sprite->setOrigin(sf::Vector2f(0, 0));
	sprite->setScale(sf::Vector2f(SAMUS_SCALE, SAMUS_SCALE));
	sprite->setPosition(sf::Vector2f(50, HEIGHT - 150));
	drawable = sprite;
}
RPG_Samus::~RPG_Samus()
{
	delete sprite;
	sprite = nullptr;
	delete texture;
	texture = nullptr;
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
		sprite->setPosition(sprite->getPosition() + sf::Vector2f(40.0f, 0));
	}
	if (Input::IsKeyDown(sf::Keyboard::Q))
	{
		sprite->setPosition(sprite->getPosition() + sf::Vector2f(-40.0f, 0));
	}
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		sprite->setPosition(sprite->getPosition() - sf::Vector2f(0, JUMP_FORCE));
	}
}
sf::FloatRect RPG_Samus::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f RPG_Samus::Position() const
{
	return sprite->getPosition();
}
void RPG_Samus::SetWindowSize(const sf::Vector2f& _size)
{
	windowSize = _size;
}
void RPG_Samus::SetPosition(const sf::Vector2f& _position)
{
	if (sprite == nullptr) return;
	sprite->setPosition(_position);
}
void RPG_Samus::OnDraw(Window* _window)
{
	GameObject::OnDraw(_window);
}
#pragma endregion

