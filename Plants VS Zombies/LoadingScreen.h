#pragma once
#include "Screen.h"
class LoadingScreen :public Screen
{
private:
	static int updated;
	int progress;
	sf::Texture bgTexture;
	//sf::Texture daizyTexture;
	sf::Sprite loadbarDirt;
	sf::Texture lbdTexture;
	sf::Sprite loadbarGrass;
	sf::Texture lbgTexture;
	sf::Sprite sodRoll;
	sf::Texture sodRollTexture;
	sf::Sprite logo;
	sf::Texture logoTexture;
	sf::Text start;
	sf::Font font;
public: 
	LoadingScreen(sf::RenderWindow *window);
	void Draw() const;
	string Update();
};

