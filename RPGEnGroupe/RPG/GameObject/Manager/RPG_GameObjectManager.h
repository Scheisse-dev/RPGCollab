#pragma once

#include "../../../Singleton/Singleton.h"
#include <vector>

class GameObject;
class RPG_GameObjectManager :
    public Singleton<RPG_GameObjectManager>
{
#pragma region f/p
private:
    std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
    std::vector<GameObject*> objectToDestroy = std::vector<GameObject*>();
#pragma endregion
#pragma region constructor
public:
    RPG_GameObjectManager() = default;
#pragma endregion
#pragma region methods
public:
    void Register(GameObject* _gameObject);
    void UnRegister(GameObject* _gameObject);
    void Update();
    void Draw(class Window* _window);
    void CheckCollisions();
    void DestroyAllRequests();
    void DestroyAllObjects();
#pragma endregion
#pragma region override
protected:
    void OnDestroy() override;
#pragma endregion

};

