#include "PeaShooter.h"

PeaShooter::PeaShooter(int row, int col) : Plant(row, col)
{
	animation = 0;
	name = "PeaShooter";
	texture.loadFromFile("Resources/Images/peas.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width, height));
	sprite.setPosition(277 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 100;
	shooting = false;
}

void PeaShooter::Shoot()
{
}

void PeaShooter::GetDamage()
{
}

void PeaShooter::Act()
{
}

void PeaShooter::Update()
{
}
