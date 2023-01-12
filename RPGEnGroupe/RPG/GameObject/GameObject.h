#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

class Window;

class GameObject : public Object
{
protected:
	sf::Drawable* drawableSamus = nullptr;
	sf::Drawable* drawablePalpatine = nullptr;
	sf::Drawable* drawablePotionMana = nullptr;
	sf::Drawable* drawablePotionHeal = nullptr;
	sf::Drawable* drawablePotionManaText = nullptr;
	sf::Drawable* drawablePotionHealText = nullptr;

public:
	GameObject();
	GameObject(const GameObject& _copy);
	~GameObject() override;

public:

	virtual void OnUpdate();
	virtual void OnDraw(Window* _window);
	virtual void OnCollisionEnter(GameObject* _object);
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual sf::Vector2f Position() const = 0;
};

