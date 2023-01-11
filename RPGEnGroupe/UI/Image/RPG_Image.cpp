#include "RPG_Image.h"


RPG_Image::RPG_Image(Window* _owner, const char* _path) : UIElement(_owner)
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (!texture->loadFromFile(_path))
	{
		Free();
		return;
	}
	sprite->setTexture(*texture);
}

RPG_Image::RPG_Image(const RPG_Image& _copy) : UIElement(_copy)
{
	sprite = _copy.sprite;
	texture = _copy.texture;
}

RPG_Image::~RPG_Image()
{
	Free();
}

void RPG_Image::Free()
{
	delete sprite;
	sprite = nullptr;
	delete texture;
	texture = nullptr;
}

sf::FloatRect RPG_Image::GlobalBounds() const
{
	return sprite->getGlobalBounds();
}

void RPG_Image::SetPosition(const sf::Vector2f& _position)
{
}

void RPG_Image::SetScale(const sf::Vector2f& _scale)
{
}

void RPG_Image::Draw(Window* _window)
{
}

void RPG_Image::SetOrigin(const sf::Vector2f& _origin)
{
}

sf::FloatRect RPG_Image::GetGlobalBounds() const
{
	return sf::FloatRect();
}
