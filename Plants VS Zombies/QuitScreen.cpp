#include "QuitScreen.h"
QuitScreen::QuitScreen(sf::RenderWindow* window) {
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/titlescreen.jpg");
	background.setTexture(bgTexture);
	BlockTexture.loadFromFile("Resources/Images/Block.png");
	Block.setTexture(BlockTexture);
	Block.setPosition(275, 100);
	QUIT.setFont(font);
	Cancel.setFont(font);
	QuitBlockText.setFont(font);

	QUIT.setString("QUIT");
	Cancel.setString("CANCEL");
	QuitBlockText.setString("            QUIT  \nDo you want to quit?\n");
	font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
	QUIT.setCharacterSize(18);
	QUIT.setPosition(200, 200);
	Cancel.setCharacterSize(18);
	QuitBlockText.setCharacterSize(29);
	QUIT.setFillColor(sf::Color::Blue);
	Cancel.setFillColor(sf::Color::Green);
	QuitBlockText.setFillColor(sf::Color::Blue);
	QuitBlockText.setPosition(370, 270);
	QUIT.setPosition(410, 395);
	Cancel.setPosition(560, 395);
	
}



void QuitScreen::Draw() const
{


	window->draw(background);
	window->draw(Block);
	window->draw(QUIT);
	window->draw(Cancel);
	window->draw(QuitBlockText);
}

string QuitScreen::Update()
{
	return "";
}
