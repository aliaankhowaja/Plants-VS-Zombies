#include "Zombie.h"

Zombie::Zombie() {
	//srand(time(0));
	//row = rand() % 6;
	x = 1000;
	//row = row * 30.5;
}

sf::Sprite& Zombie::GetSprite() {
	return sprite;
}

int Zombie::GetRow()
{
	return row;
}
