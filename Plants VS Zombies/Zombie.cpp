#include "Zombie.h"

Zombie::Zombie() {
	srand(time(0));
	SpawnRow = rand() % 6;
	startPos = 1000;
	row = SpawnRow * 30.5;
}

sf::Sprite& Zombie::GetSprite() {
	return ZombieSprite;
}