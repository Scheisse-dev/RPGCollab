#include "RPG_Label.h"

#include "../../Window/Window.h"

RPG_Label::RPG_Label(Window* _owner, const char* _text) : RPG_UIElement(_owner)
{
	text = new sf::Text();
	text->setString(_text);
	font = new sf::Font();
	if (!font->loadFromFile(LABEL_FONT))
	{
		Free();
		return;
	}
	text->setFont(*font);
}

RPG_Label::RPG_Label(const RPG_Label& _copy) : RPG_UIElement(_copy)
{
	text = _copy.text;
	font = _copy.font;
}

RPG_Label::~RPG_Label()
{
	Free();
}

void RPG_Label::Free()
{
	delete text;
	text = nullptr;
	delete font;
	font = nullptr;
}

void RPG_Label::SetCharacterSize(const int _size)
{
	text->setCharacterSize(_size);
}

void RPG_Label::SetColor(const sf::Color& _color)
{
	text->setFillColor(_color);
}

void RPG_Label::SetFont(const sf::Font& _font)
{
	text->setFont(_font);
}

void RPG_Label::SetText(const char* _text)
{
	text->setString(_text);
}

void RPG_Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}

void RPG_Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale);
}

void RPG_Label::Draw(Window* _window)
{
	if (text != nullptr)
		_window->Draw(text);
}

void RPG_Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}

sf::FloatRect RPG_Label::GetGlobalBounds() const
{
	return text->getGlobalBounds();
}
