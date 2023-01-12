#include "Window.h"
#include "../Time/Time.h"
#include "../Event/Event.h"
#include "../RPG/DataBase/DataBase.h"
#include "../UI/Image/RPG_Image.h"
#include "BaseMenu/BaseMenu.h"
#include <format>

#pragma region constructor
Window::Window(const int _width, const int _height, const char* _title)
{
	title = _title;
}
Window::~Window()
{
	Close();
	for (std::pair<const char*, BaseMenu*> _pair : menus)
	{
		delete _pair.second;
	}
	menus.clear();
	delete window;
}
#pragma endregion

#pragma region methods
void Window::Update()
{
	sf::Event _event = sf::Event();
	sf::Clock _clock = sf::Clock();
	while (window->isOpen())
	{
		Time::deltaTime = _clock.restart().asSeconds();
		while (window->pollEvent(_event))
		{
			// TODO event if not focus ?
			if (!window->hasFocus() && !eventIfNotFocus)
				continue;
			Event::currentEvent = &_event;
			OnReceiveEvent(_event);
			break;
		}
		//UIElementManager::Instance()->Update();
		OnUpdate();
		window->clear();
		OnDraw();
		window->display();
	}
}
void Window::Open()
{
	InitMenus();
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title);
	Update();
}
void Window::Close()
{
	if (!window->isOpen())
		return;
	window->close();
}
bool Window::IsOpen() const
{
	return window->isOpen();
}
bool Window::HasFocus() const
{
	return window->hasFocus();
}
void Window::SetFrameLimit(const int _frame)
{
	window->setFramerateLimit(_frame);
}
void Window::Draw(sf::Drawable* _drawable)
{
	window->draw(*_drawable);
}
void Window::SetBackground(const char* _path)
{
	background = new RPG_Image(this, _path);
}
void Window::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Closed)
		Close();
}
sf::RenderWindow* Window::Renderer() const
{
	return window;
}
void Window::CloseAllMenus()
{
	for (std::pair<const char*, BaseMenu*> _menu : menus)
		_menu.second->Close();
}
void Window::OpenMenu(const char* _name)
{
	CloseAllMenus();
	if (!menus.contains(_name))
	{
		throw std::exception(std::format("Menu {} doesn't exist", _name).c_str());
	}
	menus[_name]->Open();
}
void Window::RegisterMenu(const char* _name, BaseMenu* _menu)
{
	menus.insert(std::pair(_name, _menu));
}
void Window::InitMenus() { }
#pragma endregion
