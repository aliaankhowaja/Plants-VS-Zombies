#include "NewPlayerInput.h"

NewPlayerInput::NewPlayerInput(sf::RenderWindow* window)
{
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/titlescreen.jpg");
	background.setTexture(bgTexture);
	BlockTexture.loadFromFile("Resources/Images/Block.png");
	NewUserBlock.setTexture(BlockTexture);
	NewUserBlock.setPosition(275, 100);

	font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");


	NewUser.setString("      NewUser\nEnter Your Name:");
	NewUser.setFont(font);
	NewUser.setCharacterSize(30);
	NewUser.setFillColor(sf::Color::Cyan);
	NewUser.setPosition(390, 225);

	OK.setString("OK");
	OK.setFont(font);
	OK.setCharacterSize(24);
	OK.setFillColor(sf::Color::Cyan);
	OK.setPosition(410, 395);

	Cancel.setString("Cancel");
	Cancel.setFont(font);
	Cancel.setCharacterSize(24);
	Cancel.setFillColor(sf::Color::Cyan);
	Cancel.setPosition(545, 392);
}

void NewPlayerInput::Draw() const
{
	window->draw(background);
	window->draw(NewUserBlock);
	window->draw(NewUser);
	window->draw(OK);
	window->draw(Cancel);


}

string NewPlayerInput::Update()
{
	return "";
}
