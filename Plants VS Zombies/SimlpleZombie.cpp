#include "SimlpleZombie.h"
SimlpleZombie::SimlpleZombie():Zombie() {
	name = "simple zombie";
	health = 500;
	dps = 50;
	ZombieTexture.loadFromFile("Resources/Images/zombies/simple_zombie.png");
	ZombieSprite.setTexture(ZombieTexture);
	sf::IntRect source(0, 30.5, 50, 50);
	if (clock.getElapsedTime().asSeconds() > 1.0f) {
		if (source.left == 600)
			source.left = 0;
		else
			source.left += 50;
		ZombieSprite.setTextureRect(source);
		clock.restart();
	}
	
	speed = 30;
	ZombieSprite.setPosition(600, SpawnRow);
	moving = true;

}