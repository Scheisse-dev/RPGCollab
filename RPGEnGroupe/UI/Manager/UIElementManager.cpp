#include "UIElementManager.h"

#include "../RPG_UIElement.h"

void UIElementManager::Register(RPG_UIElement* _element)
{
	elements.push_back(_element);
}

void UIElementManager::Unregister(RPG_UIElement* _element)
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (elements[i] == _element)
		{
			elements.erase(elements.begin() + i);
			break;
		}
	}
}

void UIElementManager::Update()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		elements[i]->OnUpdate();
	}
}

void UIElementManager::OnDestroy()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		delete elements[i];
	}
	elements.clear();
}
