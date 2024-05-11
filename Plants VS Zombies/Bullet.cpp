#include "Bullet.h"
#include <iostream>
using namespace std;
int Bullet::bulletID = 0;
Bullet::Bullet()
{
	clock.restart();
	texture.loadFromFile("Resources/Images/pea.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	row = 0;
	x = 0;
	id = bulletID;
	bulletID++;
	exists = false;
	destroyed = false;
	destroyedAnimation = 0;
}
Bullet::Bullet(int x, int row)
{
	clock.restart();
	texture.loadFromFile("Resources/Images/pea.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, 90 + row * 100);
	this->row = row;
	this->x = x;
	this->id = bulletID;
	bulletID++;
	exists = true;
	destroyed = false;
	destroyedAnimation = 0;
}

sf::Sprite& Bullet::GetSprite() 
{
	return sprite;
}

int Bullet::GetRow() const 
{
	return row;
}

int Bullet::GetX() const {
	return x;
}

int Bullet::GetID() const
{
	return id;
}

void Bullet::Revive()
{

	exists = true;
	destroyed = false;
	destroyedAnimation = 0;
	texture.loadFromFile("Resources/Images/pea.png");
	sprite.setTextureRect(sf::IntRect(0,0,28,28));
}

void Bullet::SetPosition(int column, int row)
{

	this->row = row;
	this->x = 290 + column * 80;
	sprite.setPosition(x, 90 + row * 100);
	
}

bool Bullet::GetExists() const
{
	return exists;
}

void Bullet::SetID()
{
	Bullet::bulletID = 0;
}

bool Bullet::Update()
{
	
	//cout << clock.getElapsedTime().asMilliseconds() << endl;
	if (((int)clock.getElapsedTime().asMilliseconds() / 2) && !destroyed)
	{
		if (x > 1000) {
			texture.loadFromFile("Resources/Images/peaSplats.png");
			sprite.setTextureRect(sf::IntRect(destroyedAnimation * 24, 0, 24, 24));
			destroyedAnimation++;
			destroyed = true;
			return exists;
		}
		x++;
		sprite.setPosition(x, 90 + row * 100);
		clock.restart();
	}
	else if (((int)clock.getElapsedTime().asMilliseconds() / 40) && destroyed) {
		if (destroyedAnimation == 4) {
			exists = false;
			return exists;
		}
		sprite.setTextureRect(sf::IntRect(destroyedAnimation * 24, 0, 24, 24));
		x+=5;
		sprite.setPosition(x, 90 + row * 100);
		destroyedAnimation++;
		clock.restart();
	}
	return exists;
}

Bullet::~Bullet()
{
	cout << "dsff";
}

