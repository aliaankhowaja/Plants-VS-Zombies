#include "Zombie.h"
Zombie::Zombie():SpawnRow(rand()%6) {}
sf::Sprite& Zombie::GetSprite() {
	return ZombieSprite;
}