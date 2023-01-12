#include "GameObject.h"
#include "Manager/RPG_GameObjectManager.h"
#include "../../Window/Window.h"

GameObject::GameObject()
{
	RPG_GameObjectManager::Instance()->Register(this);
}

GameObject::GameObject(const GameObject& _copy)
{
	drawableSamus = _copy.drawableSamus;
	drawablePalpatine = _copy.drawablePalpatine;
}

GameObject::~GameObject()
{
	delete drawableSamus;
	drawableSamus = nullptr;
	delete drawablePalpatine;
	drawablePalpatine = nullptr;
}

void GameObject::OnUpdate()
{
}

void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawableSamus);
	_window->Draw(drawablePalpatine);
}

void GameObject::OnCollisionEnter(GameObject* _object)
{}