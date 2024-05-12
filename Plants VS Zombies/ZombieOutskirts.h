#pragma once
#include "Level.h"

class ZombieOutskirts :public Level
{
private:
	int updated;
	/*SimpleZombie* f1;
	DancingZombie* f2;
	FootballZombie* f3;
	FlyingZombie* f4;*/
public:
	ZombieOutskirts(sf::RenderWindow* window);
	virtual string Update();
	virtual void Draw() const;
};

