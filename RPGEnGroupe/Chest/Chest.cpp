#include "Chest.h"
#include "../RPG/Game/RPG_Game.h"

#pragma region constructor
Chest::Chest()
{
	sprite = new sf::Sprite(); 
	texture = new sf::Texture();


	if (isOpen == false)
		if (!texture->loadFromFile("../chestClose.png")) return; 
	if (isOpen == true)
		if (!texture->loadFromFile("../chestOpen.png")) return;



}

Chest::~Chest()
{
	delete sprite;
	sprite = nullptr; 
	delete texture;
	texture = nullptr; 
}
void Chest::SetPosition()
{
}
void Chest::SetScale()
{
}
#pragma endregion constructor
#pragma region methods


#pragma endregion methods
