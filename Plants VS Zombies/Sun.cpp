#include "Sun.h"
#include<iostream>
using namespace std;
Sun::Sun(): width(78), height(78)
{
	texture.loadFromFile("Resources/Images/sun.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 78, 78));
	exists = false;
	destinationY = 0;
	x = 0;
	y = 0;
	clock.restart();
	animation = 0;
}

bool Sun::Clicked(int mouseX, int mouseY)
{
	bool inBounds = (mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height);
	if (inBounds) exists = false;
	return inBounds;
}

void Sun::Update() {
	if (((int)clock.getElapsedTime().asMilliseconds() / 50))
	{
		sprite.setTextureRect(sf::IntRect(animation * width, 0, width, height));
		animation++;
		if (animation == 22) animation = 0;
		clock.restart();
		if (y > destinationY) return;
		y++;
		sprite.setPosition(x, y);
	}
}

sf::Sprite& Sun::GetSprite()
{
	return sprite;
}

void Sun::SetPosition(int x, int y, int destinationY)
{
	this->x = x;
	this->y = y;
	this->destinationY = destinationY;
}

bool Sun::GetExists() const
{
	return exists;
}

void Sun::SetExists(bool exists)
{
	this->exists = exists;
}
