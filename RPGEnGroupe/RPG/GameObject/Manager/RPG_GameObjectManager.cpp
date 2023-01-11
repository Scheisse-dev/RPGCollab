#include "RPG_GameObjectManager.h"
#include "../../GameObject/GameObject.h"
#include "../../../Window/Window.h"

void RPG_GameObjectManager::Register(GameObject* _gameObject)
{
	gameObjects.push_back(_gameObject);
}

void RPG_GameObjectManager::UnRegister(GameObject* _gameObject)
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (gameObjects[i] == _gameObject)
		{
			gameObjects.erase(gameObjects.begin() + 1);
			break;
		}
	}
}

void RPG_GameObjectManager::Update()
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		gameObjects[i]->OnUpdate();
	}
}

void RPG_GameObjectManager::Draw(Window* _window)
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		gameObjects[i]->OnDraw(_window);
	}
}

void RPG_GameObjectManager::CheckCollisions()
{
	for (GameObject* _a : gameObjects)
	{
		for (GameObject* _b : gameObjects)
		{
			if (_a == _b || !_a->GetGlobalBounds().contains(_b->Position())) continue;
			_b->OnCollisionEnter(_a);
		}
	}
}

void RPG_GameObjectManager::OnDestroy()
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
		delete gameObjects[i];
	gameObjects.clear();
}