#pragma once
#include "../../Window/BaseMenu/BaseMenu.h"

class RPG_Button;
class RPG_Image;

class RPG_MainMenu : public BaseMenu
{
#pragma region f/p
private:
	RPG_Image* logoTitle = nullptr;
	RPG_Button* playButton = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RPG_MainMenu(Window* _owner);
	virtual ~RPG_MainMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitLogoTitle();
	void InitPlayButton();
public:
	RPG_Button* PlayButton() const;
#pragma endregion methods
#pragma region override
public:
	void Draw();
#pragma endregion override
};

