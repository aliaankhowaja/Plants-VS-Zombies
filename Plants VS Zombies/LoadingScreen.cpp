#include "LoadingScreen.h"
#include <iostream>

int LoadingScreen::updated = 0;
LoadingScreen::LoadingScreen(sf::RenderWindow *window)
{
	progress = 0;
	this->window = window;
	//std::cout << window->getSize().x <<", " << window->getSize().y<<std::endl;
	bgTexture.loadFromFile("Resources/Images/titlescreen.jpg");
	background. setTexture(bgTexture);
	lbdTexture.loadFromFile("Resources/Images/LoadbarDirt.png");

	loadbarDirt.setTexture(lbdTexture);
	loadbarDirt.setPosition(350, 520);


	logoTexture.loadFromFile("Resources/Images/PvZ_logo.png");
	logo.setTexture(logoTexture);
	logo.setPosition(150, 10);



	lbgTexture.loadFromFile("Resources/Images/LoadbarGrass.png");
	loadbarGrass.setTexture(lbgTexture);
	loadbarGrass.setPosition(350, 500);
	loadbarGrass.setTextureRect(sf::IntRect(0, 0, 0, 0));
	sodRollTexture.loadFromFile("Resources/Images/SodRoll.png");
	sodRoll.setTexture(sodRollTexture);
	sodRoll.setPosition(340, 450);
	sodRoll.setScale(1.1, 1.1);
	font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
	start.setFont(font);
	start.setCharacterSize(25);
	start.setPosition(420, 528);
	start.setFillColor(sf::Color(255, 255, 255, 150));
	start.setString("Click to Start!");
	//start.setStyle(sf::Text::Bold);
	//sodRoll.setOrigin(sodRoll.getGlobalBounds().width / 2, sodRoll.getGlobalBounds().height / 2);
	//loadbarDirt.setPosition(window->getSize().x)
}

void LoadingScreen::Draw() const {
	window->draw(background);
	window->draw(logo);
	window->draw(loadbarDirt);
	window->draw(loadbarGrass);
	if (progress < 100) window->draw(sodRoll);
	//if (progress == 100) 
		window->draw(start);
	//else window->draw(start);
}

string LoadingScreen::Update() {
	updated++;
	if (updated % 30 == 0 && progress < 100) {
		progress++;
		loadbarGrass.setTextureRect(sf::IntRect(0, 0, int(314 * progress / 100), 33));
		
		sodRoll.setPosition(340 + int(300 * progress / 100), 450 + int(42 * (float)progress / 100));
		float scale = 1.1 - ((float)progress / 100) * 0.6;
		sodRoll.setScale(scale, scale);
		//sodRoll.setOrigin(sodRoll.getGlobalBounds().width / 2, sodRoll.getGlobalBounds().height / 2);
		//sodRoll.rotate(10);

	}
	sf::Event e;
	while (window->pollEvent(e)) {
		if (e.type == sf::Event::MouseButtonPressed && progress == 100) {
			return "StartGame";
		}
	}
	return "";

	//std::cout << window->getSize().x << ", " << window->getSize().y << std::endl;
}