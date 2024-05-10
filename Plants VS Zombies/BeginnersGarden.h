#pragma once
#include "Level.h"
#include"SimlpleZombie.h"
class BeginnersGarden :public Level
{
private:
	int updated;
public:
	BeginnersGarden(sf::RenderWindow* window);
	virtual string Update();
	virtual void Draw() const;
};

