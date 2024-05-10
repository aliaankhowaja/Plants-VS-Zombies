#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

class Zombie
{
protected:
	string name;
	int speed;
	int health;
	int dps;
	sf::Sprite ZombieSprite;
	sf::Texture ZombieTexture;
	sf::Clock clock;
	int SpawnRow;
	bool moving;

public:
	Zombie();
	
	sf::Sprite& GetSprite();
	virtual void Update() = 0;
	virtual void GetDps() = 0;
	virtual void Act() = 0;
};

