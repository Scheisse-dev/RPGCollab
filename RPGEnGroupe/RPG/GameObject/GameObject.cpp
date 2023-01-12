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
	drawablePotionMana = _copy.drawablePotionMana;
	drawablePotionHeal = _copy.drawablePotionHeal;
	drawablePotionManaText = _copy.drawablePotionManaText;
	drawablePotionHealText = _copy.drawablePotionHealText;
}

GameObject::~GameObject()
{
	delete drawableSamus;
	drawableSamus = nullptr;
	delete drawablePalpatine;
	drawablePalpatine = nullptr;
	delete drawablePotionMana;
	drawablePotionMana = nullptr;
	delete drawablePotionHeal;
	drawablePotionHeal = nullptr;
	delete drawablePotionHealText;
	drawablePotionHealText = nullptr;
	delete drawablePotionManaText;
	drawablePotionManaText = nullptr;
}

void GameObject::OnUpdate()
{
}

void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawableSamus);
	_window->Draw(drawablePalpatine);
	_window->Draw(drawablePotionMana);
	_window->Draw(drawablePotionHeal);
	_window->Draw(drawablePotionManaText);
	_window->Draw(drawablePotionHealText);
}

void GameObject::OnCollisionEnter(GameObject* _object)
{}