#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class Window;

class RPG_UIElement : public Object
{
#pragma region f/p
protected:
	bool isActive = false;
	Window* owner = nullptr;
#pragma endregion f/P
#pragma region constructor
public:
	RPG_UIElement() = default;
	RPG_UIElement(Window* _owner);
	RPG_UIElement(const RPG_UIElement& _copy);
	~RPG_UIElement() override;
#pragma endregion constructor
#pragma region methods
public:
	virtual sf::Vector2f GetPosition() = 0;
	virtual void SetPosition(const sf::Vector2f& _position) = 0;
	virtual void SetScale(const sf::Vector2f& _scale) = 0;
	virtual void Draw(Window* _window) = 0;
	virtual void SetOrigin(const sf::Vector2f& _origin) = 0;
	virtual void OnUpdate();
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	void SetActive(const bool _status);
#pragma endregion methods
};


