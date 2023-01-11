#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class Chest
{
#pragma region f/p
private:
	sf::Texture* texture = nullptr;
	sf::Sprite* sprite = nullptr;

	bool isOpen = false;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Chest(); 
	~Chest(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetPosition();
	void SetScale(); 
#pragma endregion methods


};

