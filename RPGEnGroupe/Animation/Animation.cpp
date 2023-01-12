#include "Animation.h"



#pragma region constructor/destructor
Animation::Animation(sf::Sprite* _sprite, const char* _frame1, const char* _frame2)
{
	clock = new sf::Clock;
	texture = new sf::Texture;

	frame1 = _frame1; 
	frame2 = _frame2;
	 
	sprite = _sprite;

	Anime2Frames();
}



Animation::Animation(sf::Sprite* _sprite, const char* _frame1, const char* _frame2, const char* _frame3)
{
	clock = new sf::Clock;
	texture = new sf::Texture;

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
	
	float _elapsed = clock->getElapsedTime().asSeconds();
	if (_elapsed <= sf::seconds(0.5f).asSeconds())
	{
		if (!texture->loadFromFile(frame1)) return;
	}
	if (_elapsed >= sf::seconds(1.f).asSeconds())
	{
		if (!texture->loadFromFile(frame2)) return;
		
	}
	if (_elapsed >= sf::seconds(2.f).asSeconds())
		clock->restart();
	sprite->setTexture(*texture);
}

void Animation::Anime3Frames()
{
	float _elapsed = clock->getElapsedTime().asSeconds();
	if (_elapsed <= sf::seconds(0.5f).asSeconds())
	{
		if (!texture->loadFromFile(frame1)) return;
	}
	if (_elapsed >= sf::seconds(0.5f).asSeconds() && _elapsed <= sf::seconds(1.f).asSeconds())
	{
		if (!texture->loadFromFile(frame2)) return;
		clock->restart();
	}
	if (_elapsed >= sf::seconds(1.f).asSeconds())
	{
		if (!texture->loadFromFile(frame3)) return;
		clock->restart();
	}
	sprite->setTexture(*texture);
}
	
const char* Animation::GetFrame(const int _frameNumber)
{

	if (_frameNumber == 1)
		return frame1;
	if (_frameNumber == 2)
		return frame2;
	if (_frameNumber == 3)
		return frame3;

	throw std::exception("[ANIMATION] (getFrame) frames number doesn't valid !");
	return ""; 
}

void Animation::AnimationUpdate(const int _frameNumber)
{
	if (_frameNumber == 2)
		Anime2Frames();
	if (_frameNumber == 3)
		Anime3Frames();

	if(_frameNumber > 3 || _frameNumber <2)
		throw std::exception("[ANIMATION] (Animation update) frames number doesn't valid !");

}

#pragma endregion methods



