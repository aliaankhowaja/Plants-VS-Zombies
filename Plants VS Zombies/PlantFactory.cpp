#include "PlantFactory.h"
#include <iostream>
#include "structures.h"
#include "SunFlower.h"
#include "PeaShooter.h"
#include "CherryBomb.h"
#include "Wallnut.h"
#include "Repeater.h"
#include "FumeShroom.h"
#include "SnowPea.h"

PlantFactory::PlantFactory(int numPlants, sf::RenderWindow *window)
{
	selectedPlant = 0;
	this->window = window;
	plantSelected = false;
	this->numPlants = numPlants;
	cardsTexture.loadFromFile("Resources/Images/cards.png");
	cardsSprite.setTexture(cardsTexture);
	cardsSprite.setTextureRect(sf::IntRect(0, 0, 110, numPlants * 70));
	
}

int PlantFactory::GetNumPlants()
{
	return numPlants;
}

bool PlantFactory::IsPlantSelected()
{
	return plantSelected;
}

void PlantFactory::SelectPlant(int x, int y)
{
	int plant = y / 70;
	if (x < 110 && x>0 && plant < numPlants) // checks for the seed packet bounds
	{
		selectedPlant = plant;
		switch (selectedPlant) {
		case 0:
			cursor.SetTexture("Resources/Images/suns.png");
			break;
		case 1:
			cursor.SetTexture("Resources/Images/peas.png");
			break;
		case 2:
			cursor.SetTexture("Resources/Images/wallnut.png");
			break;
		case 3:
			cursor.SetTexture("Resources/Images/cherrybomb.png");
			break;
		case 4:
			cursor.SetTexture("Resources/Images/repeater.png");
			break;
		case 5:
			cursor.SetTexture("Resources/Images/snowpea.png");
			break;
		case 6:
			cursor.SetTexture("Resources/Images/peas.png");
			break;
		default:
			break;
		}
		cursor.SetTextureRect(0, 0, 68, 72);
		gridSprite = cursor.sprite;
		gridSprite.setColor(sf::Color(255, 255, 255, 180));
		plantSelected = true;
	}
}

void PlantFactory::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	bool inGameScreen = mouseX > 0 && mouseX < 1000 && mouseY > 0 && mouseY < 600;
	if (plantSelected && inGameScreen) {
		cursor.SetPosition(mouseX-36, mouseY-36);
	}
	if (InGrid()) {
		int w = 80;
		int row = (mouseY - 80) / 100;
		int col = (mouseX - 230) / 80;
		gridSprite.setPosition(238 + col * 80, 90 + row * 100);
	}
}

void PlantFactory::Draw() const
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	window->draw(cardsSprite);
	int row = (mouseY - 80) / 100;
	int col = (mouseX - 230) / 80;
	if(InGrid() && plantSelected && !plants[row][col]) window->draw(gridSprite);
	if (plantSelected ) {
		window->draw(cursor.sprite);
	}
}

bool PlantFactory::InGrid() const
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	bool inGrid = mouseX > 230 && mouseX < 985 && mouseY > 90 && mouseY < 560;
	return inGrid;
}

Plant* PlantFactory::NewPlant(int mouseX, int mouseY)
{
	int row = (mouseY - 80) / 100;
	int col = (mouseX - 230) / 80;
	Plant* plant = nullptr;
	//cout << selectedPlant << endl;
	switch (selectedPlant)
	{
	case 0:
		plant = new SunFlower(row, col);
		break;
	case 1:
		plant = new PeaShooter(row, col);
		break;
	case 2:
		plant = new Wallnut(row, col);
		break;
	case 3:
		plant = new CherryBomb(row, col);
		break;
	case 4:
		plant = new Repeater(row, col);
		break;
	case 5:
		plant = new SnowPea(row, col);
		break;
	case 6:
		plant = new FumeShroom(row, col);
		break;
	default:
		break;
	}
	plantSelected = false;
	plants[row][col] = plant;
	return plant;
}

void PlantFactory::UnSelectPlant()
{
	plantSelected = false;
	return;
}

