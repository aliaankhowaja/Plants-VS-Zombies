#pragma once
#include "Screen.h"
#include "Plant.h"
#include "PlantFactory.h"
#include "SFML/Window/Mouse.hpp"
#include "structures.h"
#include "Bullet.h"
#include "ZombieFactory.h"
#include "Zombie.h"
#include "SunFactory.h"
#include "LawnMover.h"
class Level :public Screen
{
protected:
	int progress;
	static const int rows = 5, columns = 9;
	sf::Text sunDisplay;
	sf::Font font;
	GameObject* cursor;
	string type;
	Plant* plants[rows][columns];
	PlantFactory* plantFactory;
	int zombieRows[rows];
	ZombieFactory* zombieFactory;
	Bullet *bullets[rows][20];
	int bulletRows[rows];
	int suns;
	Zombie* zombies[5][10];
	SunFactory* sunFactory;
	LawnMover* lawnMovers[rows];
	sf::Clock sunClock;
	sf::Clock zombieClock;
	int maxZombies;
	int generatedZombies;
	float lvlProgress;
	bool something;
	//delete from here
	Zombie* zmb;
	const int maxSpawnInterval, minSpawnInterval;
	sf::Sprite progressBar;
	sf::Sprite progressBarFill;
	sf::Sprite progressBarHead;
	sf::Texture progressBarTexture;
	sf::Texture progressBarFillTexture;
	sf::Texture progressBarHeadTexture;

	///number of zombies in lvl====int
	//num zombies genereated ====int 
	//progressss =====int

	//Grid* grid;
public:
	Level();
	void SetPlant(Plant* plant, int row, int column);
	Plant* GetPlant(int row, int column);
	void DrawPlants() const;
	void UpdatePlants();
	void killZombies();
	virtual string Update() = 0;
	virtual void Draw() const = 0;
	void NewBullet(int x, int row);
	void DrawBullets() const;
	void UpdateBullets();
	void DrawLawnMovers() const;
	void UpdateLawnMovers();
	void Shoot();
	void GenerateSuns();
	void GenerateZombies();
	void DrawZombies() const;
	void UpdateZombies();
};

