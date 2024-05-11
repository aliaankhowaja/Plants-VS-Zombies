#include "LawnMover.h"

LawnMover::LawnMover(int row)
{
	x = 150;
	this->row = row;
	texture.loadFromFile("Resources/Images/lawnMover.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, 95 + 100 * row);
	exists = true;
	used = false;
	clock.restart();
}

void LawnMover::Update()
{
	if (used) {
		if ((int)clock.getElapsedTime().asMilliseconds() / 20) {
			x += 4;
			sprite.setPosition(x, 90 + 80 * row);
			clock.restart();
		}
	}
}

sf::Sprite& LawnMover::GetSprite()
{
	return sprite;
}

void LawnMover::Use()
{
	used = true;
}

bool LawnMover::GetExists() const
{
	return exists;
}

bool LawnMover::GetUsed() const
{
	return used;
}
