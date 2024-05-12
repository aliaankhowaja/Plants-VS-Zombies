#include "ZombieOutskirts.h"


#include <iostream>
ZombieOutskirts::ZombieOutskirts(sf::RenderWindow* window)
{
	name = "ZombieOutskirts";
	rewardSprite.setTextureRect(sf::IntRect(0, 210, 110, 70));
	maxZombies = 10;
	zombieFactory = new ZombieFactory();
	plantFactory = new PlantFactory(3, window);
	updated = 0;
	sunFactory = new SunFactory(window);
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/BeginnersGardenBackground.png");
	background.setTexture(bgTexture);
	background.setTextureRect(sf::IntRect(25, 0, 1000, 600));
	//lives = 0;
}

string ZombieOutskirts::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	sf::Event e;

	if (lives<=0)
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
	//cout << progress << endl;
	progressBar.setTextureRect(sf::IntRect(0, 0, 160 - 150 * (float)progress / 100, 25));
	int row = (mouseY - 80) / 100;
	int col = (mouseX - 230) / 80;
	int rewardX = rewardSprite.getGlobalBounds().getPosition().x;
	int rewardY = rewardSprite.getGlobalBounds().getPosition().y;
	while (window->pollEvent(e)) {
		bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;
		
		if(mouseClick){
			bool inRewardBounds = (mouseX > rewardX && mouseX < rewardX + 110) && (mouseY > rewardY && mouseY < rewardY + 70);
			if ((mouseX > 905 && mouseX < 990) && (mouseY > 7 && mouseY < 39)) gamePaused = true;
			if (progress >= 100) {
				return "Zombie Outskirts Compelete";
			}
			suns += sunFactory->AddSuns(mouseX , mouseY);

			plantFactory->SetSuns(suns);
			if (!plantFactory->IsPlantSelected()) {
				plantFactory->SelectPlant(mouseX, mouseY);	
			}
			else if(plantFactory->InGrid() && !plants[row][col]) {
				plants[row][col] = plantFactory->NewPlant(mouseX, mouseY);
				if (plants[row][col]) suns = plantFactory->GetSuns();
				//if (plants[row][col]->GetName() == "PeaShooter") {
					//NewBullet(290 + col * 80, row);
				//}
			}
		}
		if (e.type == sf::Event::KeyPressed && 
			plantFactory->IsPlantSelected() && 
			e.key.code == 36) // if esc key pressed
		{
			plantFactory->UnSelectPlant(); // unselect plant
		}
	}
	/*int once = 0;
	if (once == 0) {
		//////GenerateZombies();
		once++;
	}*/
	
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

void ZombieOutskirts::Draw() const
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


