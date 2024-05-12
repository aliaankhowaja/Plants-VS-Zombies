#include "Repeater.h"
#include <iostream>
Repeater::Repeater(int row, int column) : PeaShooter(row, column)
{
	animation = 0;
	name = "Peashooter";
	texture.loadFromFile("Resources/Images/repeater.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width-5, height));
	sprite.setPosition(238 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 50;
}

void Repeater::GetDamage()
{
}

bool Repeater::Act()
{
	shooting = true;
	if ((int)clock.getElapsedTime().asSeconds() / 2)
	{
		//cout << "fd" <<endl;
		clock.restart();
		return true;
	}
	return false;
}

void Repeater::Update()
{
	//upfd++;
	//if (upfd % 100)return;
	//animation++;
	//if (animation == 17) animation = 0;
	//if(animation < 11) sprite.setTextureRect(sf::IntRect(animation*68, 0, width, height));
	//else sprite.setTextureRect(sf::IntRect(animation * 68, 0, width-5, height));
	//std:://cout << animation << endl;
}
