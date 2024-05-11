#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
#include"SimlpleZombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
#include"FlyingZombie.h"
#include <ctime>
class ZombieFactory
{
private:
	sf::RenderWindow* window;
	Zombie* zombies[6];
public:
	ZombieFactory();
	void Draw();


};

