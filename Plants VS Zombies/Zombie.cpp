#include "Zombie.h"

Zombie::Zombie() {
	//srand(time(0));
	//row = rand() % 6;
	x = 920;
	animation = 0;
	//row = row * 30.5;
}

sf::Sprite& Zombie::GetSprite() {
	return sprite;
}

int Zombie::GetRow()
{
	return row;
}

//int Zombie::GetX()
//{
//	return x;
//}

void Zombie::GetDamage(int d)
{
	health -= d;
}

int Zombie::GetHealth() const {
	return health;
}

void Zombie::Move()
{
	moving = 1;
}

int Zombie::GetX() const
{
	return x;
}

