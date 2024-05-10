#pragma once
#include "Screen.h"
#include "Plant.h"
#include "PlantFactory.h"
#include "SFML/Window/Mouse.hpp"
#include "structures.h"
#include "Bullet.h"
#include "Zombie.h"
class Level :public Screen
{
protected:
	static const int rows = 6, columns = 9;
	GameObject* cursor;
	string type;
	Plant* plants[rows][columns];
	PlantFactory* plantFactory;
	int zombieRows[rows];
	BulletContainer *bullets[6];
	int bulletRows[6];
	Zombie* zombie;
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
	void Shoot();
};

