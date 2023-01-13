#pragma once
#include <SFML/Graphics.hpp>
#include "../Object/Object.h"

class Animation
{
#pragma region f/p
private:
	class RPG_Image* sprite = nullptr;
	sf::Texture* texture = nullptr;
	sf::Texture* texture1 = nullptr;
	sf::Texture* texture2 = nullptr;
	const char* frame1 = nullptr; 
	const char* frame2 = nullptr;
	const char* frame3 = nullptr;
	float speed = 0;
	float initialSpeed = 0; 
public:
	sf::Clock* clock = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Animation(class RPG_Image* _sprite, const char* _frame1, const char* _frame2,const float _initialSpeed, const float _speed);
	Animation(class RPG_Image* _sprite, const char* _frame1, const char* _frame2, const char* _frame3,const float _initialSpeed, const float _speed);
	~Animation(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Anime2Frames();
	void Anime3Frames();
	const char* GetFrame(const int _frameNumber);
	void AnimationUpdate(const int _frameNumber);
	void SetScale(const sf::Vector2f& _vector);
#pragma endregion methods
};