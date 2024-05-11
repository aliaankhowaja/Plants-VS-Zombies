#pragma once
#include"Screen.h"
class NewPlayerInput:public Screen 
{
private:
	sf::Sprite NewUserBlock;
	sf::Texture BlockTexture;
	sf::Text NewUser;
	sf::Font font;
	sf::Text OK;
	sf::Text Cancel;
	
public:
	NewPlayerInput(sf::RenderWindow* window);
	void Draw() const;
	string Update();

};

