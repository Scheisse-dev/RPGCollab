#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class Window;

class UIElement : public Object
{
#pragma region f/p
protected:
	bool isActive = false;
	Window* owner = nullptr;
#pragma endregion f/P
#pragma region constructor
public:
	UIElement(Window* _owner);
	UIElement(const UIElement& _copy);
	~UIElement() override;
#pragma endregion constructor
#pragma region methods
public:
	virtual void SetPosition(const sf::Vector2f& _position) = 0;
	virtual void SetScale(const sf::Vector2f& _scale) = 0;
	virtual void Draw(Window* _window) = 0;
	virtual void SetOrigin(const sf::Vector2f& _origin) = 0;
	virtual void OnUpdate();
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	void SetActive(const bool _status);
#pragma endregion methods
};

