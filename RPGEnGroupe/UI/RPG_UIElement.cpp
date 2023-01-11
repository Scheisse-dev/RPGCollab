#include "RPG_UIElement.h"
#include "Manager/UIElementManager.h"

#pragma region constructor
RPG_UIElement::RPG_UIElement(Window* _owner)
{
	owner = _owner;
	UIElementManager::Instance()->Register(this);
}

RPG_UIElement::RPG_UIElement(const RPG_UIElement& _copy)
{
	owner = _copy.owner;
	isActive = _copy.isActive;
}
RPG_UIElement::~RPG_UIElement()
{
	UIElementManager::Instance()->Unregister(this);
}
#pragma endregion constructor
void RPG_UIElement::OnUpdate() { }

void RPG_UIElement::SetActive(const bool _status)
{
	isActive = _status;
}