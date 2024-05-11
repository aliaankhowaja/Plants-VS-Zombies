#pragma once
#include "Screen.h"
#include "Plant.h"
#include "PlantFactory.h"
#include "SFML/Window/Mouse.hpp"
#include "structures.h"
#include "Bullet.h"
#include"ZombieFactory.h"
#include "Zombie.h"
#include "SunFactory.h"
#include "LawnMover.h"
class Level :public Screen
{
protected:
	static const int rows = 6, columns = 9;
	sf::Text sunDisplay;
	sf::Font font;
	GameObject* cursor;
	string type;
	Plant* plants[rows][columns];
	PlantFactory* plantFactory;
	int zombieRows[rows];
	BulletContainer *bullets[6];
	int bulletRows[6];
	ZombieFactory ZombieFac;
	//BulletContainer *bullets[6];
	Bullet *bullets[rows][20];
	int bulletRows[rows];
	int suns;
	Zombie* zombie;
	SunFactory* sunFactory;
	LawnMover* lawnMovers[rows];
	sf::Clock clock;
	//Grid* grid;
public:
	Level();
	void SetPlant(Plant* plant, int row, int column);
	Plant* GetPlant(int row, int column);
	void DrawPlants() const;
	void UpdatePlants();
	virtual string Update() = 0;
	virtual void Draw() const = 0;
	void NewBullet(int x, int row);
	void DrawBullets() const;
	void UpdateBullets();
	void DrawLawnMovers() const;
	void UpdateLawnMovers();
	void Shoot();
	void GenerateSuns();
};

