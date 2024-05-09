#pragma once
#include <SFML/Graphics.hpp>
#include "structures.h"
#include "Plant.h"
class PlantFactory
{
private:
	//static const int totalPlants; // total number of plants in whole game
	sf::RenderWindow* window;
	bool plantSelected;
	int numPlants, selectedPlant;
	sf::Sprite background;
	sf::Texture bgTexture;
	sf::Sprite cardsSprite;
	sf::Texture cardsTexture;
	sf::Sprite gridSprite;
	//sf::Texture cursorTexture;
	GameObject cursor;
	Plant* plants[6][9];


public:
	PlantFactory(int numPlants, sf::RenderWindow* window);
	int GetNumPlants();
	//sf::Sprite& GetCard(int i);
	bool IsPlantSelected();
	void SelectPlant(int x, int y);
	void Update();
	void Draw() const;
	Plant* NewPlant(int mouseX, int mouseY);
	bool InGrid() const;
	void UnSelectPlant();
};

