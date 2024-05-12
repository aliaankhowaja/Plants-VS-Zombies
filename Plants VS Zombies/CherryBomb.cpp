#include "CherryBomb.h"
#include <iostream>
CherryBomb::CherryBomb(int row, int column) : Plant(row, column)
{
	animation = 0;
	name = "CherryBomb";
	texture.loadFromFile("Resources/Images/cherrybomb.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width-5, height));
	sprite.setPosition(238 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 50;
}

void CherryBomb::GetDamage()
{
}

bool CherryBomb::Act()
{
	if ((int)clock.getElapsedTime().asSeconds() / 2)
	{
		clock.restart();
		return true;
	}
	return false;
}

void CherryBomb::Update()
{}
