#pragma once
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
class Plant
{
protected:
	string name;
	sf::Sprite sprite;
	sf::Texture texture;
	int animation, sunLight, health;
	const int row, column, height, width;
public:
	Plant(int row, int column);
	virtual void GetDamage() = 0;
	virtual void Act() = 0;
	sf::Sprite& GetSprite();
	virtual void Update() = 0;

};

