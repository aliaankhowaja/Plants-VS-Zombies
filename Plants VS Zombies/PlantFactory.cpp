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
	suns = 0;
	selectedPlant = 0;
	this->window = window;
	plantSelected = false;
	this->numPlants = numPlants;
	cardsTexture.loadFromFile("Resources/Images/cards.png");
	cardsSprite.setTexture(cardsTexture);
	cardsSprite.setTextureRect(sf::IntRect(0, 0, 110, numPlants * 70));
	invalidColor = sf::Color(0, 0, 0, 100);
	validColor = sf::Color::Transparent;
	for (int i = 0; i < numPlants; i++) {
		cardInvalid[i].setSize(sf::Vector2f(110, 70));
		cardInvalid[i].setFillColor(invalidColor);
		cardInvalid[i].setPosition(0, 70 * i);
	}
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
	//TODO: don't select plants if less suns
	int plant = y / 70;
	sf::Color color = cardInvalid[plant].getFillColor();

	if (x < 110 && x>0 && plant < numPlants && color == validColor) // checks for the seed packet bounds
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
	if (suns >= 200) {
		for (int i = 0; i < numPlants; i++) {
			cardInvalid[i].setFillColor(validColor);
		}
	} else if (suns >= 150) {
		for (int i = 0; i < numPlants; i++) {
			cardInvalid[i].setFillColor(validColor);
		}cardInvalid[4].setFillColor(invalidColor);
	} else if (suns >= 100) {
		for (int i = 0; i < numPlants; i++) {
			cardInvalid[i].setFillColor(validColor);
		}
		cardInvalid[3].setFillColor(invalidColor);
		cardInvalid[4].setFillColor(invalidColor);
		cardInvalid[5].setFillColor(invalidColor);
	} else if (suns >= 75) {
		for (int i = 0; i < numPlants; i++) {
			cardInvalid[i].setFillColor(invalidColor);
		}
		cardInvalid[2].setFillColor(validColor);
		cardInvalid[6].setFillColor(validColor);
	} else if (suns >= 50) {
		for (int i = 0; i < numPlants; i++) {
			cardInvalid[i].setFillColor(invalidColor);
		}
		cardInvalid[2].setFillColor(validColor);
	} else {
		for (int i = 0; i < numPlants; i++) {
			cardInvalid[i].setFillColor(invalidColor);
		}
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
	for (int i = 0; i < numPlants; i++) {
		window->draw(cardInvalid[i]);
	}
	if (plantSelected) {
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
		suns -= 100;
		break;
	case 1:
		plant = new PeaShooter(row, col);
		suns -= 100;
		break;
	case 2:
		plant = new Wallnut(row, col);
		suns -= 50;
		break;
	case 3:
		plant = new CherryBomb(row, col);
		suns -= 150;
		break;
	case 4:
		plant = new Repeater(row, col);
		suns -= 200;
		break;
	case 5:
		plant = new SnowPea(row, col);
		suns -= 150;
		break;
	case 6:
		plant = new FumeShroom(row, col);
		suns -= 75;
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

void PlantFactory::SetSuns(int suns)
{
	this->suns = suns;
}

int PlantFactory::GetSuns() const
{
	return suns;
}

