#pragma once
#include <SFML/Graphics.hpp>

class Window
{
#pragma region f/p
private:
	bool isOpen = false;
	const char* title = "Default";
protected:
	sf::RenderWindow* window = nullptr;
	bool eventIfNotFocus = false;
#pragma endregion
#pragma region constructor
public: 
	Window() = default;
	Window(const char* _title);
	Window(const Window& _copy) = delete;
	virtual ~Window();
#pragma endregion
#pragma region methods
private: 
	void Update();
public:
	void Open();
	void Close();
	bool IsOpen();
	bool HasFocus();
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);
protected:
	virtual void OnDraw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnReceiveEvent(const sf::Event& _event);
#pragma endregion
};

