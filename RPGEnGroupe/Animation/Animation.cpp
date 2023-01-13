#include "Animation.h"
#include "../UI/Image/RPG_Image.h"

#pragma region constructor/destructor
Animation::Animation(RPG_Image* _sprite, const char* _frame1, const char* _frame2, const float _initialSpeed, const float _speed)
{
	clock = new sf::Clock;
	texture = new sf::Texture;
	texture1 = new sf::Texture;
	frame1 = _frame1; 
	frame2 = _frame2;

	if (frame1 != nullptr)
		texture->loadFromFile(frame1);
	if (frame2 != nullptr)
		texture1->loadFromFile(frame2);

	initialSpeed = _initialSpeed;
	speed = _speed;
	sprite = _sprite;

}

Animation::Animation(RPG_Image* _sprite, const char* _frame1, const char* _frame2, const char* _frame3, const float _initialSpeed, const float _speed)
{
	clock = new sf::Clock;
	texture = new sf::Texture;
	texture1 = new sf::Texture;
	texture2 = new sf::Texture;

	frame1 = _frame1;
	frame2 = _frame2;
	frame3 = _frame3;

	if (frame1 != nullptr)
		texture->loadFromFile(frame1);
	if (frame2 != nullptr)
		texture1->loadFromFile(frame2);
	if (frame3 != nullptr)
		texture2->loadFromFile(frame3);

	initialSpeed = _initialSpeed;
	speed = _speed; 
	sprite = _sprite; 

	
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
	if (_elapsed <= sf::seconds(initialSpeed).asSeconds())
	{
		sprite->SetTexture(*texture);
	}
	if (_elapsed >= sf::seconds(initialSpeed + speed).asSeconds())
	{
		sprite->SetTexture(*texture1);
	}
	if (_elapsed >= sf::seconds(initialSpeed + 2 * speed).asSeconds())
		clock->restart();
}

void Animation::Anime3Frames()
{
	float _elapsed = clock->getElapsedTime().asSeconds();
	if (_elapsed <= sf::seconds(initialSpeed).asSeconds())
	{
		sprite->SetTexture(*texture);
	}
	if (_elapsed >= sf::seconds(initialSpeed + speed).asSeconds() && _elapsed <= sf::seconds(initialSpeed + 2*speed).asSeconds())
	{
		sprite->SetTexture(*texture1);
		clock->restart();
	}
	if (_elapsed >= sf::seconds(initialSpeed + 3* speed).asSeconds())
	{
		sprite->SetTexture(*texture2);
		clock->restart();
	}
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
void Animation::SetScale(const sf::Vector2f& _vector)
{
	sprite->SetScale(_vector);
}
#pragma endregion methods



