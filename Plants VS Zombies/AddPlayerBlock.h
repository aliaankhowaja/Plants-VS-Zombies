#pragma once
#include "Screen.h"
class AddPlayerBlock :
    public Screen
{
private:
	sf::Texture BlockTexture;
	sf::Sprite Block;
	sf::Font font;
	sf::Text Rename;
	sf::Text Delete;
	sf::Text OK;
	sf::Text Cancel;
public:
	AddPlayerBlock(sf::RenderWindow* window);
	void Draw() const;
	string Update();
};

