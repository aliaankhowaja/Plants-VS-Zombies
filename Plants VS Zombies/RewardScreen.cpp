#include "RewardScreen.h"
#include <iostream>
using namespace std;
RewardScreen::RewardScreen(int reward, sf::RenderWindow* window)
{
	this->reward = reward;
	switch (reward) {
	case 1:
		//plantTexture.loadFromFile()
		plantTexture.loadFromFile("Resources/Images/wallnut.png");
		plantSprite.setTexture(plantTexture);
		plantSprite.setTextureRect(sf::IntRect(0, 0, 68, 72));
		plantSprite.setPosition(500, 200);
		break;
	case 2:
		//plantTexture.loadFromFile()
		plantTexture.loadFromFile("Resources/Images/cherrybomb.png");
		plantSprite.setTexture(plantTexture);
		plantSprite.setTextureRect(sf::IntRect(0, 0, 68, 72));
		plantSprite.setPosition(500, 200);
		break;
	case 3:
		//plantTexture.loadFromFile()
		plantTexture.loadFromFile("Resources/Images/repeater.png");
		plantSprite.setTexture(plantTexture);
		plantSprite.setTextureRect(sf::IntRect(0, 0, 68, 72));
		plantSprite.setPosition(500, 200);
		break;
	}
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
	description.setFont(font);
	Menu.setString("Return to Menu");
	Menu.setCharacterSize(35);
	Menu.setPosition(400, 20);
	NextLvl.setPosition(430, 520);
	NextLvl.setCharacterSize(37);
	NextLvl.setString("Next Level!");
	switch (reward) {
	case 1:
		description.setString("Wallnut: Blocks \nThe Zombies");
		break;
	case 2:
		description.setString("Cherry Bomb: \ndestroyes zombies \nin region");
		break;
	case 3:
		description.setString("Repeater: Shoots \n2 peas \nat a time");
		break;
	}
	description.setCharacterSize(30);
	description.setPosition(400, 350);

}
void RewardScreen::Draw() const
{
	window->draw(background);
	window->draw(plantSprite);
	for(int i=0;i<2;i++)
	window->draw(Buttons[i]);
	window->draw(NextLvl);
	window->draw(Menu);
	window->draw(description);
}

string RewardScreen::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	sf::Event e;
	while (window->pollEvent(e)) {
		bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;

		if (mouseClick) {

			bool inNextBounds = (mouseX > 360 && mouseX < 360 + 360) && (mouseY > 500 && mouseY < 500 + 100);
			bool inMenuBounds = (mouseX > 355 && mouseX < 355 + 360) && (mouseY > 0 && mouseY < 0 + 100);
			if (inMenuBounds)
				return "LoadingComplete";
			if (inNextBounds) {
				cout << reward;
				switch (reward) {
				case 1:
					return "level2";
					break;
				case 2:
					return "level3";
					break;
				case 3:
					return "LoadingComplete";
					break;
				}
			}
		}
	}
	return "";
}