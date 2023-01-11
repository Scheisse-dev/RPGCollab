#include "RPG_MainMenu.h"
#include "../../UI/Image/RPG_Image.h"
#include "../../UI/Button/RPG_Button.h"
#include "../../Window/Window.h"

#pragma region constructor
RPG_MainMenu::RPG_MainMenu(Window* _owner) : BaseMenu(_owner)
{
	InitLogoTitle();
	InitPlayButton();
}
RPG_MainMenu::~RPG_MainMenu()
{
}
#pragma endregion

#pragma region methods
void RPG_MainMenu::InitLogoTitle()
{
	logoTitle = new RPG_Image(owner, "../Donnees/Title.png");
	logoTitle->SetPosition(sf::Vector2f((WIDTH / 2) - 50, 70));
	logoTitle->SetScale(sf::Vector2f(0.5f, 0.5f));
	logoTitle->SetOrigin(sf::Vector2f(logoTitle->GlobalBounds().width / 2, logoTitle->GlobalBounds().height / 2));
	elements.push_back(logoTitle);
}
void RPG_MainMenu::InitPlayButton()
{
	playButton = new RPG_Button(owner, "../Donnees/play.png");
	playButton->SetScale(sf::Vector2f(0.05f, 0.05f));
	const sf::Vector2f _position = sf::Vector2f((WIDTH / 2) - 30, HEIGHT / 2 + 20);
	playButton->SetPosition(_position);
	elements.push_back(playButton);
}
RPG_Button* RPG_MainMenu::PlayButton() const
{
	return playButton;
}
#pragma endregion

#pragma region overide
void RPG_MainMenu::Draw()
{
	BaseMenu::Draw();
}
#pragma endregion

