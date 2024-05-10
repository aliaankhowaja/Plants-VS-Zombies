#include "FumeShroom.h"
#include <iostream>
FumeShroom::FumeShroom(int row, int column) : Plant(row, column)
{
	animation = 0;
	name = "SunFolwer";
	texture.loadFromFile("Resources/Images/suns.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width-5, height));
	sprite.setPosition(238 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 50;
}

void FumeShroom::GetDamage()
{
}

bool FumeShroom::Act()
{
	return false;
}

void FumeShroom::Update()
{
	//upfd++;
	//if (upfd % 100)return;
	//animation++;
	//if (animation == 17) animation = 0;
	//if(animation < 11) sprite.setTextureRect(sf::IntRect(animation*68, 0, width, height));
	//else sprite.setTextureRect(sf::IntRect(animation * 68, 0, width-5, height));
	//std:://cout << animation << endl;
}
