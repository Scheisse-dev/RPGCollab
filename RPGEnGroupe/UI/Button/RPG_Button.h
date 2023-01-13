#pragma once
#include "../RPG_UIElement.h"
#include "../../Event/Delegate/Delegate.h"

class RPG_Image;

class RPG_Button : public RPG_UIElement
{

#pragma region f/p
private:
	RPG_Image* image = nullptr;

public:
	Delegate<void> OnClick = nullptr;

#pragma endregion
#pragma region constructor/destructor
public:
	RPG_Button(Window* _owner, const char* _path);
	RPG_Button(const RPG_Button& _copy);
	virtual ~RPG_Button() override;

#pragma endregion

public:

#pragma region override
public:


	// Inherited via RPG_UIElement
	virtual void SetPosition(const sf::Vector2f& _position) override;

	virtual void SetScale(const sf::Vector2f& _scale) override;

	virtual void Draw(Window* _window) override;

	virtual void SetOrigin(const sf::Vector2f& _origin) override;

	virtual void OnUpdate() override;

	virtual sf::FloatRect GetGlobalBounds() const override;

#pragma endregion

	// Inherited via RPG_UIElement
	virtual sf::Vector2f GetPosition() override;
};

