#pragma once
#include "Screen.h"
class MainMenuScreen : public Screen
{
public:
	MainMenuScreen(sf::RenderWindow* window);
	void Draw() const;
	string Update();
};

