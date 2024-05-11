#pragma once
#include"Screen.h"
class QuitScreen:public Screen
{
private:
	sf::Sprite Block;
	sf::Texture BlockTexture;
	sf::Text QUIT;
	sf::Text Cancel;
	sf::Text QuitBlockText;
	sf::Font font;
public:
	QuitScreen(sf::RenderWindow* window);
	void Draw() const;
	string Update();
	
};

