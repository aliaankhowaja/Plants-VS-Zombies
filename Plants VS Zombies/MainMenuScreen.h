#pragma once
#include "Screen.h"

class MainMenuScreen : public Screen
{
private:
	sf::Texture cloudsTexture[6];
	sf::Sprite clouds[6];
	sf::Sprite tombstone;
	sf::Texture tombstoneTexture;
	sf::Texture TresTexture;
	sf::Sprite Tree;
	sf::Texture HouseTexture;
	sf::Sprite House;
	sf::Texture AdventureTexture;
	sf::Sprite Adventure;
	sf::Texture WoodBoardTexture[2];
	sf::Sprite WoodBoard[2];
	sf::Texture helpTexture;
	sf::Sprite Help;
	sf::Texture OptionsTexture;
	sf::Sprite Options;
	sf::Texture QuitTexture;
	sf::Sprite Quit;


public:
	MainMenuScreen(sf::RenderWindow* window);
	void Draw() const;
	string Update();
};

