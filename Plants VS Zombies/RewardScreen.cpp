#include "RewardScreen.h"

RewardScreen::RewardScreen(sf::RenderWindow* window)
{
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/AwardScreen_Back.png");
	background.setTexture(bgTexture);
	ButtonTexture.loadFromFile("Resources/Images/options_backtogamebutton0.png");
	Buttons[0].setTexture(ButtonTexture);
	Buttons[0].setPosition(360, 500);
	Buttons[1].setPosition(355, 0);
	Buttons[1].setTexture(ButtonTexture);
	font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
	Menu.setFont(font);
	NextLvl.setFont(font);
	Menu.setString("Return to Menu");
	Menu.setCharacterSize(35);
	Menu.setPosition(400, 20);
	NextLvl.setPosition(430, 520);
	NextLvl.setCharacterSize(37);
	NextLvl.setString("Next Level!");

}
void RewardScreen::Draw() const
{


	window->draw(background);
	for(int i=0;i<2;i++)
	window->draw(Buttons[i]);
	window->draw(NextLvl);
	window->draw(Menu);
}

string RewardScreen::Update()
{
	return "";
}