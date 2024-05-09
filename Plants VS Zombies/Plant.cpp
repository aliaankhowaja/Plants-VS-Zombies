#include "Plant.h"

Plant::Plant(int row, int column): row(row), column(column), height(72), width(72)
{
}

sf::Sprite& Plant::GetSprite()
{
	return sprite;
}
