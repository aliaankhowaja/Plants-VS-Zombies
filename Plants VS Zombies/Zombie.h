#pragma once
#include<ctime>
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

class Zombie
{
protected:
	string name;
	double speed;
	int health;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock clock;
	bool moving;
	int animation;
	int x, row;

public:
	
	Zombie();
	sf::Sprite& GetSprite();
	virtual string Update() = 0;
	//virtual void GetDps() = 0;
	virtual void Act() = 0;
	int GetRow();
	void GetDamage(int x);
	int getX()const;
};

