#include "RPG_Game.h"
#include "../Menu/RPG_MainMenu.h"
#include "../../UI/Button/RPG_Button.h"
#include "../../UI/image/RPG_Image.h"
#include "../GameObject/Manager/RPG_GameObjectManager.h"
#include "../Samus/RPG_Samus.h"
#include "../DataBase/DataBase.h"
#include "../../UI/Manager/UIElementManager.h"
#include <iostream>

#pragma region constructor
RPG_Game::RPG_Game() : Window(WIDTH, HEIGHT, "PALPATOUILLE et la revanche de Samus")
{
	InitBackGround();
}
RPG_Game::~RPG_Game()
{
	delete background;
	background = nullptr;
}
#pragma endregion

#pragma region methods
void RPG_Game::Start()
{
	RPG_GameObjectManager::Instance()->DestroyAllObjects();
	CloseAllMenus();
	isStarted = true;
	samus = new RPG_Samus();
	samus->SetWindowSize(sf::Vector2f(WIDTH, HEIGHT));
	samus->SetPosition(sf::Vector2f(0, 0));
	SetBackground("../Donnees/Backgroung_Game.png");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetPosition(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(1.8f, 1.5f));
}
void RPG_Game::InitBackGround()
{
	background = new RPG_Image(this, "../Donnees/background.jpg");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetPosition(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(3.0f, 3.5f));
}
#pragma endregion

#pragma region override
void RPG_Game::OnDraw()
{
	background->Draw(this);
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		_pair.second->Draw();
	if (!isStarted)
		return;
	RPG_GameObjectManager::Instance()->Draw(this);

}
void RPG_Game::OnUpdate()
{
	try
	{
		UIElementManager::Instance()->Update();
		if (!isStarted)
			return;
		RPG_GameObjectManager* _instance = RPG_GameObjectManager::Instance();
		_instance->CheckCollisions();
		_instance->Update();
		_instance->DestroyAllRequests();
	}
	catch (const std::exception& _e)
	{
		std::cout << _e.what() << std::endl;
	}
}
void RPG_Game::InitMenus()
{
	RPG_MainMenu* _mainMenu = new RPG_MainMenu(this);
	_mainMenu->PlayButton()->OnClick.SetDynamic(this, &RPG_Game::Start);
	_mainMenu->Open();
	RegisterMenu(MAIN_MENU, _mainMenu);
}
void RPG_Game::OnReceiveEvent(const sf::Event& _event)
{
	Window::OnReceiveEvent(_event);
	if (_event.type == sf::Event::Resized)
	{
		samus->SetWindowSize(sf::Vector2f(WIDTH, HEIGHT));
	}
}
#pragma endregion