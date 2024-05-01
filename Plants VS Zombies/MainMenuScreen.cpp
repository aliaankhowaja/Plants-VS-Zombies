#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(sf::RenderWindow* window)
{
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/MainMenu/MainMenuBG.png");
	background.setTexture(bgTexture);
}

void MainMenuScreen::Draw() const
{
	window->draw(background);
}

string MainMenuScreen::Update()
{
	return "";
	//return "StartGame";
}

