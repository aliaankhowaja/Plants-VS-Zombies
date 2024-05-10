#include "SnowPea.h"
#include <iostream>
SnowPea::SnowPea(int row, int column) : Plant(row, column)
{
	animation = 0;
	name = "SunFolwer";
	texture.loadFromFile("Resources/Images/snowpea.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, width-5, height));
	sprite.setPosition(238 + column * 80, 90 + row * 100);
	health = 100;
	sunLight = 50;
}

void SnowPea::GetDamage()
{
}

bool SnowPea::Act()
{
	return false;
}

void SnowPea::Update()
{
	//upfd++;
	//if (upfd % 100)return;
	//animation++;
	//if (animation == 17) animation = 0;
	//if(animation < 11) sprite.setTextureRect(sf::IntRect(animation*68, 0, width, height));
	//else sprite.setTextureRect(sf::IntRect(animation * 68, 0, width-5, height));
	//std:://cout << animation << endl;
}
