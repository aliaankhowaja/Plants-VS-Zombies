#pragma once
#include "Screen.h"
class LoadingScreen :public Screen
{
private:
	static int updated;
	int loading;
	sf::Texture bgTexture;
	sf::Texture daizy;
	sf::Sprite loadbarDirt;
	sf::Texture lbdTexture;
	sf::Sprite loadbarGrass;
	sf::Texture lbgTexture;
	sf::Sprite sodRoll;
	sf::Texture sodRollTexture;
public: 
	LoadingScreen(sf::RenderWindow *window);
	void Draw() const;
	void Update();
};

