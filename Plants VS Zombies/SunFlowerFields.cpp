#include "SunFlowerFields.h"


#include <iostream>
SunFlowerFields::SunFlowerFields(sf::RenderWindow* window)
{
	name = "SunFlowerFields";
	rewardSprite.setTextureRect(sf::IntRect(0, 280, 110, 70));
	maxZombies = 15;
	zombieFactory = new ZombieFactory();
	plantFactory = new PlantFactory(4, window);
	updated = 0;
	sunFactory = new SunFactory(window);
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/BeginnersGardenBackground.png");
	background.setTexture(bgTexture);
	background.setTextureRect(sf::IntRect(25, 0, 1000, 600));
	
}

string SunFlowerFields::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	sf::Event e;

	if (lives <= 0)
	{
		while (window->pollEvent(e)) {
			bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;

			if (mouseClick) {
				return "gameOver";
			}
		}
		return "";
	}
	if (gamePaused)
	{
		//cout << mouseX << " " << mouseY << endl;

		while (window->pollEvent(e)) {
			bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;

			if (mouseClick) {
				if ((mouseX > 420 && mouseX < 590) && (mouseY > 370 && mouseY < 410)) return "level2";
				else if ((mouseX > 420 && mouseX < 590) && (mouseY > 420 && mouseY < 450)) return "LoadingComplete";
				else if ((mouseX > 360 && mouseX < 650) && (mouseY > 490 && mouseY < 550)) gamePaused = false;
			}
		}
		return "";
	}
	brains.setTextureRect(sf::IntRect(0, 0, lives * 33, 31));
	progressBar.setTextureRect(sf::IntRect(0, 0, 160 - 150 * (float)progress / 100, 25));
	int row = (mouseY - 80) / 100;
	int col = (mouseX - 230) / 80;
	while (window->pollEvent(e)) {
		bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;
		if(mouseClick){
			if ((mouseX > 905 && mouseX < 990) && (mouseY > 7 && mouseY < 39)) gamePaused = true;
			if ( progress >= 100) {
				return "SunFlower Fields Compelete";
			}
			suns += sunFactory->AddSuns(mouseX , mouseY);

			plantFactory->SetSuns(suns);
			if (!plantFactory->IsPlantSelected()) {
				plantFactory->SelectPlant(mouseX, mouseY);	
			}
			else if(plantFactory->InGrid() && !plants[row][col]) {
				plants[row][col] = plantFactory->NewPlant(mouseX, mouseY);
				if (plants[row][col]) suns = plantFactory->GetSuns();
			}
		}
		if (e.type == sf::Event::KeyPressed && 
			plantFactory->IsPlantSelected() && 
			e.key.code == 36) // if esc key pressed
		{
			plantFactory->UnSelectPlant(); // unselect plant
		}
	}
	
	GenerateZombies();
	UpdateZombies();
	plantFactory->Update();
	UpdatePlants();
	UpdateBullets();
	sunFactory->Update();
	Shoot();
	GenerateSuns();
	sunDisplay.setString(to_string(suns));
	UpdateLawnMovers();
	killZombies();
	
	//zombieFactory->Update();
	return "";
}

void SunFlowerFields::Draw() const
{
	window->draw(background);
	DrawPlants();
	DrawLawnMovers();
	window->draw(pauseButton);
	window->draw(pauseText);

	plantFactory->Draw();
	window->draw(sunBank);
	window->draw(sunDisplay);
	if (progress >= 100)
		window->draw(rewardSprite);
	window->draw(progressBarFill);
	window->draw(progressBar);
	window->draw(brains);
	sunFactory->Draw();
	DrawZombies();
	DrawBullets();
	if (gamePaused) {
		window->draw(Block);
		window->draw(GamePaused);
		window->draw(Restart);
		window->draw(MainMenu);
		window->draw(BackToGame);
	}
	if (lives <= 0)
		window->draw(gameOver);
}


