#include "GameObject.h"
#include "../Manager/RPG_GameObjectManager.h"
#include "../../Window/Window.h"

GameObject::GameObject()
{
	RPG_GameObjectManager::Instance()->Register(this);
}

GameObject::GameObject(const GameObject& _copy)
{
	drawable = _copy.drawable;
}

GameObject::~GameObject()
{
	delete drawable;
	drawable = nullptr;
}

void GameObject::OnUpdate()
{
}

void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawable);
}

void GameObject::OnCollisionEnter(GameObject* _object)
{}