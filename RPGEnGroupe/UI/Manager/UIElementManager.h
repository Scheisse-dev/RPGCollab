#pragma once
#include "../Singleton/Singleton.h"
#include <vector>

class RPG_UIElement;

class UIElementManager : public Singleton<UIElementManager>
{
#pragma region f/p
private:
	std::vector<RPG_UIElement*> elements = std::vector<RPG_UIElement*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
UIElementManager() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
void Register(RPG_UIElement* _element);
	void Unregister(RPG_UIElement* _element);
	void Update();
#pragma endregion methods
#pragma region override
public:
	virtual void OnDestroy() override;
#pragma endregion override
};


