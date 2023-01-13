#pragma once
#include "../RPG_UIElement.h"
class RPG_Image : public RPG_UIElement
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_Image(Window* _owner, const char* _path);
	RPG_Image(const RPG_Image& _copy);
	virtual ~RPG_Image() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Free();
public:
	sf::FloatRect GlobalBounds() const;
	void SetTexture(sf::Texture _texture) const; 
#pragma endregion methods
#pragma region override
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
#pragma endregion override

	// Inherited via RPG_UIElement
	virtual sf::FloatRect GetGlobalBounds() const override;

	// Inherited via RPG_UIElement
	virtual void GetPosition() override;
};

