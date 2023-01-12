#pragma once
#include "../../Window/Window.h"

class RPG_Game : public Window
{
#pragma region f/p
private:
	bool isStarted = false;

	class RPG_Samus* samus = nullptr;
#pragma endregion
#pragma region constructor
public:
	RPG_Game();
	~RPG_Game();
#pragma endregion
#pragma region methods
private:
	void Start();
	void InitBackGround();
#pragma endregion
#pragma region override
protected:
	void OnDraw();
	void OnUpdate();
	void InitMenus() override;
	virtual void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion

};