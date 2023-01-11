#pragma once
#include "../Singleton/Singleton.h"
#include <vector>

class RPG_UIElement;

class UIElementManager : public Singleton<UIElementManager>
{

private:
	std::vector<RPG_UIElement*> elements = std::vector<RPG_UIElement*>();

public:
	UIElementManager() = default;

public:
	void Register(RPG_UIElement* _element);
	void Unregister(RPG_UIElement* _element);
	void Update();

public:
	virtual void OnDestroy() override;

};


