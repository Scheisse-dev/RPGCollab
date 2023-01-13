#pragma once
#include "../RPG_UIElement.h"

class RPG_Label : public RPG_UIElement
{
#pragma region f/p
private:
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Label(Window* _owner, const char* _text);
	RPG_Label(const RPG_Label& _copy);
	~RPG_Label() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Free();
	void SetCharacterSize(const int _size);
	void SetColor(const sf::Color& _color);
	void SetFont(const sf::Font& _font);
	void SetText(const char* _text);
#pragma endregion methods
#pragma region override
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
	virtual sf::FloatRect GetGlobalBounds() const override;
#pragma endregion override

	// Inherited via RPG_UIElement
	virtual sf::Vector2f GetPosition() override;
};

