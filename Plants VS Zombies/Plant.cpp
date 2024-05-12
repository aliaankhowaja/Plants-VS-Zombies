#include "Plant.h"

Plant::Plant(int row, int column): row(row), column(column), height(72), width(72)
{
}

void Plant::GetDamage()
{
	//cout << health << endl;
	health -= 20;
}

sf::Sprite& Plant::GetSprite()
{
	return sprite;
}

string Plant::GetName() const
{
	return name;
}

int Plant::GetHealth() const
{
	return health;
}
