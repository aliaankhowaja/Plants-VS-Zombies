#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
#include"SimpleZombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
#include"FlyingZombie.h"
//#include <ctime>
class ZombieFactory
{
private:
	//int levelNum, progress;
	//int zombieRows[5];
	//sf::RenderWindow* window;
	//Zombie* zombies[5];
public:
	ZombieFactory();
	Zombie* NewZombie(int zombie);
	//void Draw();

	//void Update();


};

