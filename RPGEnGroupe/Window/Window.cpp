#include "Window.h"
#include <SFML/Graphics.hpp>

#pragma region constructor
Window::Window()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
Window::~Window()
{
}
#pragma endregion

#pragma region methods
void Window::Open()
{
}
void Window::Close()
{
}
bool Window::IsOpen()
{
	return false;
}
void Window::OnDraw()
{
}
void Window::OnUpdate()
{
}
#pragma endregion

