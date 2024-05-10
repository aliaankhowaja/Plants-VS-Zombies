#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
#include"SimlpleZombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
#include"DolphinRiderZombie.h"
#include"FlyingZombie.h"
class ZombieFactory
{
private:
	sf::RenderWindow* window;
	
	sf::Sprite background;
	sf::Texture bgTexture;
	sf::Sprite cardsSprite;
	sf::Texture cardsTexture;
	Zombie* zombies;
public:
	ZombieFactory();
	void Draw() const;


};

