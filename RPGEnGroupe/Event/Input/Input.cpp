#include "Input.h"


#pragma region methods
bool Input::isKeyDown(const sf::Keyboard::Key& _key)
{
	const sf::Event* _current = Event::currentEvent;
	if (_current == nullptr) return false;
	return _current->key.code == _key && _current->type == sf::Event::KeyPressed;
		

}

bool Input::isKeyUp(const sf::Keyboard::Key& _key)
{
	const sf::Event* _current = Event::currentEvent;
	if (_current == nullptr) return false;
	return _current->key.code == _key && _current->type == sf::Event::KeyReleased;
}
bool Input::mouseIsClicked(const sf::Mouse::Button& _button)
{
	const sf::Event* _current = Event::currentEvent;
	if (_current == nullptr) return false;
	return _current->key.code == _button && _current->type == sf::Mouse::Left;
}
#pragma endregion methods