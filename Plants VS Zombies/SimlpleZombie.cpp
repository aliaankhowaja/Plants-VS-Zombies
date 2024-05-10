#include "SimlpleZombie.h"
SimlpleZombie::SimlpleZombie() {
	name = "simple zombie";
	health = 500;
	dps = 50;
	ZombieTexture.loadFromFile("Resources/Images/zombies/normalZombie.png");
	ZombieSprite.setTexture(ZombieTexture);
	sf::IntRect source(0, 0, 144, 144);
	ZombieSprite.setTextureRect(source);
	/*if (clock.getElapsedTime().asSeconds() > 1.0f) {
		if (source.left == 600)
			source.left = 0;
		else
			source.left += 50; 
		ZombieSprite.setTextureRect(source);
		clock.restart();
	}*/
	
	speed = 30;
	ZombieSprite.setPosition(600, SpawnRow);
	moving = true;

}

void SimlpleZombie::Update()
{
}

void SimlpleZombie::GetDps()
{
}

void SimlpleZombie::Act()
{
}
