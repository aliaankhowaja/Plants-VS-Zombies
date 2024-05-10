#include "PeaShooter.h"

PeaShooter::PeaShooter(int row, int col) : Plant(row, col)
{
	animation = 0;
	name = "PeaShooter";
	texture.loadFromFile("Resources/Images/peas.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width, height));
	sprite.setPosition(238 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 100;
	shooting = false;
	clock.restart();
}

void PeaShooter::Shoot()
{
	shooting = true;
}

void PeaShooter::GetDamage()
{
}

bool PeaShooter::Act()
{
	Shoot();
	if ((int)clock.getElapsedTime().asSeconds() / 2) 
	{
		clock.restart();
		return true;
	}
	return false;
}

void PeaShooter::Update()
{
}

bool PeaShooter::IsShooting()
{
	return shooting;
}
