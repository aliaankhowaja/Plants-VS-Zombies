#include "LoadingScreen.h"
#include <iostream>

int LoadingScreen::updated = 0;
LoadingScreen::LoadingScreen(sf::RenderWindow *window)
{
	loading = 0;
	this->window = window;
	std::cout << window->getSize().x <<", " << window->getSize().y<<std::endl;
	bgTexture.loadFromFile("Images/titlescreen.jpg");
	background. setTexture(bgTexture);
	lbdTexture.loadFromFile("Images/LoadbarDirt.png");

	loadbarDirt.setTexture(lbdTexture);
	loadbarDirt.setPosition(350, 520);
	
	lbgTexture.loadFromFile("Images/LoadbarGrass.png");
	loadbarGrass.setTexture(lbgTexture);
	loadbarGrass.setPosition(350, 500);
	loadbarGrass.setTextureRect(sf::IntRect(0, 0, 0, 0));
	sodRollTexture.loadFromFile("Images/SodRoll.png");
	sodRoll.setTexture(sodRollTexture);
	sodRoll.setPosition(340, 460);

	//loadbarDirt.setPosition(window->getSize().x)
}

void LoadingScreen::Draw() const {
	window->draw(background);
	window->draw(loadbarDirt);
	window->draw(loadbarGrass);
	window->draw(sodRoll);
}

void LoadingScreen::Update() {
	updated++;
	if (updated % 30 == 0 && loading < 100) {
		loading++;
		loadbarGrass.setTextureRect(sf::IntRect(0, 0, int(314 * loading / 100), 33));
		//sodRoll.setRotation(int(360 * loading / 100));
		sodRoll.setPosition(340 + int(250 * loading / 100), 460);
	}

	//std::cout << window->getSize().x << ", " << window->getSize().y << std::endl;
}