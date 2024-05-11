#pragma once
#include "Sun.h"
class SunFactory
{
private:
	sf::RenderWindow* window;
	Sun* suns[5];
public:
	SunFactory(sf::RenderWindow *window);
	void Update();
	int AddSuns(int mouseX, int mouseY);
	void NewSun();
	void NewSun(int column, int row);
	void Draw() const;
};

