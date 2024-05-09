#include "Wallnut.h"
#include <iostream>
Wallnut::Wallnut(int row, int column) : Plant(row, column)
{
	animation = 0;
	name = "SunFolwer";
	texture.loadFromFile("Resources/Images/wallnut.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width-5, height));
	sprite.setPosition(277 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 50;
}

void Wallnut::GetDamage()
{
}

void Wallnut::Act()
{
}

void Wallnut::Update()
{
	//upfd++;
	//if (upfd % 100)return;
	//animation++;
	//if (animation == 17) animation = 0;
	//if(animation < 11) sprite.setTextureRect(sf::IntRect(animation*68, 0, width, height));
	//else sprite.setTextureRect(sf::IntRect(animation * 68, 0, width-5, height));
	//std::cout << animation << endl;
}
