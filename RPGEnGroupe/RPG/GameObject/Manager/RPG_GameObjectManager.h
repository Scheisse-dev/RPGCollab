#pragma once

#include "../../../Singleton/Singleton.h"
#include <vector>

class GameObject;
class RPG_GameObjectManager :
    public Singleton<RPG_GameObjectManager>
{
private:
    std::vector<GameObject*> gameObjects = std::vector<GameObject*>();

public:
    RPG_GameObjectManager() = default;

public:
    void Register(GameObject* _gameObject);
    void UnRegister(GameObject* _gameObject);
    void Update();
    void Draw(class Window* _window);

public:
    void CheckCollisions();

protected:
    void OnDestroy() override;
};

