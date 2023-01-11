#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class Event : public Object
{
	static inline sf::Event* currentEvent = nullptr;

};

