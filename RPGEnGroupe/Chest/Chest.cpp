#include "Chest.h"
#include "../RPG/Game/RPG_Game.h"
#include "../Inventory/Inventory.h"
#include "../Item/RPG_Item.h"


#pragma region constructor
Chest::Chest()
{
	sprite = new sf::Sprite(); 
	texture = new sf::Texture();
	SetDrop(); 
	Update();

}



Chest::~Chest()
{
	delete sprite;
	sprite = nullptr; 
	delete texture;
	texture = nullptr; 

}
#pragma endregion constructor
#pragma region methods

void Chest::SetPosition(float _width, float _height)
{
	sprite->setPosition(_width, _height);
}
void Chest::SetScale(sf::Vector2f _size)
{
	sprite->setScale(_size);
}



void Chest::Update()
{
	if(isOpen == false)
	if (!texture->loadFromFile("../chestClose.png")) return;
	if(isOpen == true)
	if (!texture->loadFromFile("../chestOpen.png")) return;

	sprite->setTexture(*texture);
}

void Chest::SetDrop()
{
	//TODO
	

}

bool Chest::IsOpen()
{
	return isOpen;
}


#pragma endregion methods
