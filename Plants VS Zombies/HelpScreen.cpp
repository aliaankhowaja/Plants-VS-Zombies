#include "HelpScreen.h"
#include <iostream>
using namespace std;
HelpScreen::HelpScreen(sf::RenderWindow* window) {
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/Help/WhatsApp Image 2024-05-02 at 10.29.35 PM.jpeg");
	background.setTexture(bgTexture);
	background.setScale(1.4, 1.3);
	PaperTexture.loadFromFile("Resources/Images/Help/ZombieNote.png");
	Paper.setTexture(PaperTexture);
	Paper.setPosition(173, 51.5);
	WritingTexture.loadFromFile("Resources/Images/Help/Untitled-1.png");
	Writing.setTexture(WritingTexture);
	Writing.setPosition(238.5, 103.5);
	ButtonTexture.loadFromFile("Resources/Images/Help/SeedChooser_Button.png");
	Button.setTexture(ButtonTexture);
	Button.setPosition(422, 500);
	ButtonGlowTexture.loadFromFile("Resources/Images/Help/SeedChooser_Button_Glow.png");
	ButtonGLow.setTexture(ButtonGlowTexture);
	ButtonGLow.setPosition(422, 500);
}



void HelpScreen::Draw() const
{
	window->draw(background);
	window->draw(Paper);
	window->draw(Writing);
	window->draw(ButtonGLow);
	window->draw(Button);
	
}

string HelpScreen::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	sf::Event e;
	while (window->pollEvent(e)) {
		bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;

		if (mouseClick) {
			cout << mouseX << " " << mouseY << endl;
			bool inRewardBounds = (mouseX > 424 && mouseX < 573) && (mouseY > 498 && mouseY < 537);
			if (inRewardBounds)
				return "LoadingComplete";
			
		}
	}
	return "";
}