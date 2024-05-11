#include "BeginnersGarden.h"


#include <iostream>
BeginnersGarden::BeginnersGarden(sf::RenderWindow* window)
{
	ZombieFac = new ZombieFactory(window);
	zombieRows[1] = 2;
	zombieRows[3] = 2;
	plantFactory = new PlantFactory(7, window);
	
	plantFactory = new PlantFactory(2, window);
	updated = 0;
	sunFactory = new SunFactory(window);
	zombie = new SimlpleZombie();
	
	ZombieFac;

	this->window = window;
	bgTexture.loadFromFile("Resources/Images/BeginnersGardenBackground.png");
	background.setTexture(bgTexture);
	background.setTextureRect(sf::IntRect(25, 0, 1000, 600));
	
}

string BeginnersGarden::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	int row = (mouseY - 80) / 100;
	int col = (mouseX - 230) / 80;
	//cout << mouseX << ", " << mouseY << endl;
	//if (plantFactory->IsPlantSelected()) {
		//cursor->SetPosition(mouseX-36, mouseY-36);
	//}
	sf::Event e;
	while (window->pollEvent(e)) {
		bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;
		if(mouseClick){
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
	
	
	plantFactory->Update();
	UpdatePlants();
	UpdateBullets();
	sunFactory->Update();
	Shoot();
	GenerateSuns();
	sunDisplay.setString(to_string(suns));
	UpdateLawnMovers();
	return "";
}

void BeginnersGarden::Draw() const
{
	window->draw(background);
	DrawPlants();
	DrawLawnMovers();
	plantFactory->Draw();
	window->draw(sunDisplay);
	window->draw(zombie->GetSprite());
	sunFactory->Draw();
	DrawBullets();
	/*for (int i = 0; i < 20; i++) {
		cout << bullets[1][i]->GetExists();
	}cout << endl;*/
	ZombieFac->Draw();
	//if (bullet) window->draw(bullet->GetSprite());
	
	//for (int i = 0; i < plantFactory->GetNumPlants(); i++) {
	//	window->draw(plantFactory->GetCard(i));
	//}
}


