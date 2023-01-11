#pragma once
#include <SFML/Graphics.hpp>
#include "../Event.h"

class Input
{
#pragma region constructor
private:
	Input() = default; 
#pragma endregion constructor
#pragma region methods
public:
	static bool isKeyDown(const sf::Keyboard::Key& _key);
	static bool isKeyUp(const sf::Keyboard::Key& _key);
	static bool mouseIsClicked(const sf::Mouse::Button& _button);
#pragma endregion methods
};

