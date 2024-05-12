#pragma once
#include "Level.h"

class BeginnersGarden :public Level
{
private:
	int updated;
	SimpleZombie* f1;
public:
	BeginnersGarden(sf::RenderWindow* window);
	virtual string Update();
	virtual void Draw() const;
};

