#include "DancingZombie.h"
DancingZombie::DancingZombie() {
	name = "dancing zombie";
	health = 700;
	dps = 80;
	ZombieTexture.loadFromFile("Resources/Images/zombies/dancing_zombie.png");
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

	speed = 40;
	ZombieSprite.setPosition(600, 30*SpawnRow);
	moving = true;
}