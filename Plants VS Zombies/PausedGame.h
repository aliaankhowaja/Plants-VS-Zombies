#pragma once
#include <SFML/Graphics.hpp>
#include"Screen.h"
class PausedGame:public Screen
{
private:
	sf::Sprite Block;
	sf::Texture BlockTexture;
	sf::Text Restart;
	sf::Text MainMenu;
	sf::Text BackToGame;
	sf::Text GamePaused;
	sf::Font font;
public:
	PausedGame(sf::RenderWindow* window);
	void Draw() const;
	string Update();

};

