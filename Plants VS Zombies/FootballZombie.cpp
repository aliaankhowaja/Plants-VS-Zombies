#include "FootballZombie.h"
FootballZombie::FootballZombie() {
	name = "Football zombie";
	health = 750;
	dps = 85;
	ZombieTexture.loadFromFile("Resources/Images/zombies/football_zombie.png");
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
	ZombieSprite.setPosition(600, SpawnRow);
	moving = true;
}