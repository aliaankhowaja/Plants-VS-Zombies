#pragma once
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
class Plant
{
protected:
	string name;
	sf::Sprite plantSprite;
	sf::Texture plantTexture;
	int animation, sunLight, health;
	const int row, column, height, width;
public:
	virtual void GetDamage() = 0;
	virtual void Act() = 0;
	sf::Sprite& GetSprite();
	virtual void Update() = 0;

};

