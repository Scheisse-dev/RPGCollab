#include "RPG_Button.h"
#include "../../Window/Window.h"
#include "../Image/RPG_Image.h"

RPG_Button::RPG_Button(Window* _owner, const char* _path) : RPG_UIElement(_owner)
{
	image = new RPG_Image(_owner, _path);
}

RPG_Button::RPG_Button(const RPG_Button& _copy) : RPG_UIElement(_copy)
{
	image = _copy.image;
}

RPG_Button::~RPG_Button()
{
	delete image;
	image = nullptr;
}

void RPG_Button::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}

void RPG_Button::SetScale(const sf::Vector2f& _scale)
{
	image->SetScale(_scale);
}

void RPG_Button::Draw(Window* _window)
{
	image->Draw(_window);
}

void RPG_Button::SetOrigin(const sf::Vector2f& _origin)
{
	image->SetOrigin(_origin);
}

void RPG_Button::OnUpdate()
{
	if (!isActive) return;
	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && image->GlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
	{
		OnClick.Invoke();
	}
}

sf::FloatRect RPG_Button::GetGlobalBounds() const
{
	return image->GetGlobalBounds();
}

sf::Vector2f RPG_Button::GetPosition()
{
	return image->GetPosition();
}
