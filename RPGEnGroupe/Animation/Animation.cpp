#include "Animation.h"



#pragma region constructor/destructor
Animation::Animation(sf::Sprite* _sprite, const char* _frame1, const char* _frame2)
{
	clock = new sf::Clock;
	frame1 = _frame1; 
	frame2 = _frame2;

	sprite = _sprite;

	Anime2Frames();
}



Animation::Animation(sf::Sprite* _sprite, const char* _frame1, const char* _frame2, const char* _frame3)
{
	clock = new sf::Clock;

	frame1 = _frame1;
	frame2 = _frame2;
	frame3 = _frame3; 

	sprite = _sprite; 

	Anime3Frames();
}



Animation::~Animation()
{
	delete clock; 
	clock = nullptr; 
	delete sprite;
	sprite = nullptr;
	delete frame1;
	frame1 = nullptr; 
	delete frame2;
	frame2 = nullptr;
	delete frame3;
	frame3 = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void Animation::Anime2Frames()
{
	sf::Texture* _texture = new sf::Texture;
	
	if (clock->getElapsedTime().asSeconds() <= 1.0f)
	{
		if (!_texture->loadFromFile(frame1)) return;
	}
	if (clock->getElapsedTime().asSeconds() >= 1.0f && clock->getElapsedTime().asSeconds() <= 1.2f)
	{
		if (!_texture->loadFromFile(frame2)) return;
	}
	sprite->setTexture(*_texture);
	clock->restart();
}

void Animation::Anime3Frames()
{
	sf::Texture* _texture = new sf::Texture;
	if (clock->getElapsedTime().asSeconds() <= 1.0f)
	{
		if (!_texture->loadFromFile(frame1)) return;
	}
	if (clock->getElapsedTime().asSeconds() >= 1.0f && clock->getElapsedTime().asSeconds() <= 1.2f)
	{
		if (!_texture->loadFromFile(frame2)) return;
	}
	if (clock->getElapsedTime().asSeconds() >= 1.2f && clock->getElapsedTime().asSeconds() <= 1.5f)
	{
		if (!_texture->loadFromFile(frame3)) return;
	}
	sprite->setTexture(*_texture);
	clock->restart();
}
const char* Animation::GetFrame(const int _frameNumber)
{

	if (_frameNumber == 1)
		return frame1;
	if (_frameNumber == 2)
		return frame2;
	if (_frameNumber == 3)
		return frame3;

	throw std::exception("[ANIMATION] frames number doesn't valid !");
	return ""; 
}

void Animation::AnimationUpdate(const int _frameNumber)
{
	if (_frameNumber == 2)
		Anime2Frames();
	if (_frameNumber == 3)
		Anime3Frames();
	else
		throw std::exception("[ANIMATION] frames number doesn't valid !");

}

#pragma endregion methods



