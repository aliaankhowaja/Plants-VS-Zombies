#include "BeginnersGarden.h"
#include <iostream>
BeginnersGarden::BeginnersGarden(sf::RenderWindow* window)
{
	plantFactory = new PlantFactory(7, window);
	updated = 0;
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/BeginnersGardenBackground.png");
	background.setTexture(bgTexture);
	background.setTextureRect(sf::IntRect(115, 0, 1000, 600));

}

string BeginnersGarden::Update()
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	int row = (mouseY - 80) / 100;
	int col = (mouseX - 260) / 80;
	//if (plantFactory->IsPlantSelected()) {
		//cursor->SetPosition(mouseX-36, mouseY-36);
	//}
	sf::Event e;
	while (window->pollEvent(e)) {
		bool mouseClick = e.mouseButton.button == sf::Mouse::Left && e.type == sf::Event::MouseButtonPressed;
		if(mouseClick){
			if (!plantFactory->IsPlantSelected()) {
				plantFactory->SelectPlant(mouseX, mouseY);	
			}
			else if(plantFactory->InGrid() && !plants[row][col]) {
				plants[row][col] = plantFactory->NewPlant(mouseX, mouseY);
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
	//if(updated<500)updated++;
	//background.setTextureRect(sf::IntRect(115, 0, 1000, 600));
	return "";
}

void BeginnersGarden::Draw() const
{
	window->draw(background);
	DrawPlants();
	plantFactory->Draw();
	
	//for (int i = 0; i < plantFactory->GetNumPlants(); i++) {
	//	window->draw(plantFactory->GetCard(i));
	//}
}
