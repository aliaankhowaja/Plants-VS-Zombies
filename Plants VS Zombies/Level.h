#pragma once
#include "Screen.h"
#include "Plant.h"
#include "PlantFactory.h"
#include "SFML/Window/Mouse.hpp"
#include "structures.h"
class Level :public Screen
{
protected:
	static const int rows = 6, columns = 9;
	GameObject* cursor;
	string type;
	Plant* plants[rows][columns];
	PlantFactory* plantFactory;
	//Grid* grid;
public:
	Level();
	void SetPlant(Plant* plant, int row, int column);
	Plant* GetPlant(int row, int column);
	void DrawPlants() const;
	void UpdatePlants();
	virtual string Update() = 0;
	virtual void Draw() const = 0;
};

