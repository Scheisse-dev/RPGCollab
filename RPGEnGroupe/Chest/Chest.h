#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

class Chest : public Object
{
#pragma region f/p
private:
	sf::Texture* texture = nullptr;
	sf::Sprite* sprite = nullptr;
protected :
	bool isOpen = false;

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Chest();
	~Chest() override; 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetPosition(float _width, float _height);
	void SetScale(sf::Vector2f _size);
	void Update(); 
	void SetDrop();
	bool IsOpen();

#pragma endregion methods


};

