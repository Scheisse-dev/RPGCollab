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

	drawablePotionManaRod = _copy.drawablePotionManaRod;
	drawablePotionHealRod = _copy.drawablePotionHealRod;
	drawablePotionManaTextRod = _copy.drawablePotionManaTextRod;
	drawablePotionHealTextRod = _copy.drawablePotionHealTextRod;

	drawableCoin = _copy.drawableCoin;
	drawableCoinText = _copy.drawableCoinText;

	drawablePlatforme1 = _copy.drawablePlatforme1;
	drawablePlatforme2 = _copy.drawablePlatforme2;
	drawablePlatforme3 = _copy.drawablePlatforme3;
	drawablePlatforme4 = _copy.drawablePlatforme4;

	drawableChest = _copy.drawableChest;
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
	delete drawablePotionManaRod;
	drawablePotionManaRod = nullptr;
	delete drawablePotionHealRod;
	drawablePotionHealRod = nullptr;

	delete drawablePotionHealText;
	drawablePotionHealText = nullptr;
	delete drawablePotionManaText;
	drawablePotionManaText = nullptr;
	delete drawablePotionHealTextRod;
	drawablePotionHealTextRod = nullptr;
	delete drawablePotionManaTextRod;
	drawablePotionManaTextRod = nullptr;

	delete drawableCoin;
	drawableCoin= nullptr;
	delete drawableCoinText;
	drawableCoinText = nullptr;

	delete drawablePlatforme1;
	drawablePlatforme1 = nullptr;
	delete drawablePlatforme2;
	drawablePlatforme2 = nullptr;
	delete drawablePlatforme3;
	drawablePlatforme3 = nullptr;
	delete drawablePlatforme4;
	drawablePlatforme4 = nullptr;

	delete drawableChest;
	drawableChest = nullptr;
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

	_window->Draw(drawablePotionManaRod);
	_window->Draw(drawablePotionHealRod);
	_window->Draw(drawablePotionManaTextRod);
	_window->Draw(drawablePotionHealTextRod);

	_window->Draw(drawableCoin);
	_window->Draw(drawableCoinText);

	_window->Draw(drawablePlatforme1);
	_window->Draw(drawablePlatforme2);
	_window->Draw(drawablePlatforme3);
	_window->Draw(drawablePlatforme4);

	_window->Draw(drawableChest);
}

void GameObject::OnCollisionEnter(GameObject* _object)
{}