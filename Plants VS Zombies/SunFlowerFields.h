#pragma once
#include "Level.h"

class SunFlowerFields :public Level
{
private:
	int updated;
	/*SimpleZombie* f1;
	DancingZombie* f2;
	FootballZombie* f3;
	FlyingZombie* f4;*/
public:
	SunFlowerFields(sf::RenderWindow* window);
	virtual string Update();
	virtual void Draw() const;
};

