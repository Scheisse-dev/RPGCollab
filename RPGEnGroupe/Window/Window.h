#pragma once
#include "../Object/Object.h"

class Window : public Object
{
#pragma region f/p
private:
	bool isOpen = false;
	sf::RenderWindow window = sf::RenderWindow();
#pragma endregion
#pragma region constructor
public: 
	Window();
	virtual ~Window() override;
#pragma endregion
#pragma region methods
public:
	void Open();
	void Close();
	bool IsOpen();
	void OnDraw();
	void OnUpdate();
#pragma endregion
};

