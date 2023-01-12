#pragma once
#include <SFML/Graphics.hpp>
#include "../Object/Object.h"

class Animation
{
#pragma region f/p
private:
	sf::Clock* clock = nullptr; 
	sf::Sprite* sprite = nullptr;
	const char* frame1 = nullptr; 
	const char* frame2 = nullptr;
	const char* frame3 = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Animation(sf::Sprite* _sprite, const char* _frame1, const char* _frame2);
	Animation(sf::Sprite* _sprite, const char* _frame1, const char* _frame2, const char* _frame3);
	~Animation(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Anime2Frames();
	void Anime3Frames();
	const char* GetFrame(const int _frameNumber);
	void AnimationUpdate(const int _frameNumber);
#pragma endregion methods
};