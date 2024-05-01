#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(sf::RenderWindow* window)
{
	this->window = window;
	bgTexture.loadFromFile("Resources/Images/MainMenu/MainMenuBG.png");
	background.setTexture(bgTexture);
	cloudsTexture[0].loadFromFile("Resources/Images/MainMenu/SelectorScreen_Cloud1.png");
	cloudsTexture[1].loadFromFile("Resources/Images/MainMenu/SelectorScreen_Cloud2.png");
	cloudsTexture[2].loadFromFile("Resources/Images/MainMenu/SelectorScreen_Cloud4.png");
	cloudsTexture[3].loadFromFile("Resources/Images/MainMenu/SelectorScreen_Cloud5.png");
	cloudsTexture[4].loadFromFile("Resources/Images/MainMenu/SelectorScreen_Cloud6.png");
	cloudsTexture[5].loadFromFile("Resources/Images/MainMenu/SelectorScreen_Cloud7.png");
	for(int i=0;i<6;i++)
	clouds[i].setTexture(cloudsTexture[i]);
	clouds[1].setPosition(100, 30);
	clouds[2].setPosition(450, 90);
	clouds[3].setPosition(120, 110);
	clouds[4].setPosition(180, 10);
	clouds[5].setPosition(800, 35);




	TresTexture.loadFromFile("Resources/Images/MainMenu/SelectorScreen_BG_Left.png");
	Tree.setTexture(TresTexture);
	Tree.setPosition(0, -80);
	HouseTexture.loadFromFile("Resources/Images/MainMenu/MainMenuFG.png");
	House.setTexture(HouseTexture);
	House.setPosition(200,250);
	tombstoneTexture.loadFromFile("Resources/Images/MainMenu/SelectorScreen_BG_Right.png");
	tombstone.setTexture(tombstoneTexture);
	tombstone.setPosition(137, 40);

	AdventureTexture.loadFromFile("Resources/Images/MainMenu/SelectorScreen_Adventure_highlight.png");
	Adventure.setTexture(AdventureTexture);
	Adventure.setPosition(475,80);
	
	WoodBoardTexture[0].loadFromFile("Resources/Images/MainMenu/SelectorScreen_WoodSign1.png");
	WoodBoard[0].setTexture(WoodBoardTexture[0]);
	WoodBoard[0].setPosition(30,0);
	WoodBoardTexture[1].loadFromFile("Resources/Images/MainMenu/SelectorScreen_WoodSign2.png");
	WoodBoard[1].setTexture(WoodBoardTexture[1]);
	WoodBoard[1].setPosition(30,135);
	helpTexture.loadFromFile("Resources/Images/MainMenu/SelectorScreen_Help1.png");
	Help.setTexture(helpTexture);
	Help.setPosition(715,515);
	OptionsTexture.loadFromFile("Resources/Images/MainMenu/SelectorScreen_Options1.png");
	Options.setTexture(OptionsTexture);
	Options.setPosition(630,489);
	QuitTexture.loadFromFile("Resources/Images/MainMenu/SelectorScreen_Quit1.png");
	Quit.setTexture(QuitTexture);
	Quit.setPosition(785,500);
}

void MainMenuScreen::Draw() const
{
	window->draw(background);
	for (int i = 0; i < 6; i++) {
		window->draw(clouds[i]);
	}
	window->draw(House);
	window->draw(Tree);
	window->draw(tombstone);
	window->draw(Adventure);
	for (int i = 0; i < 2; i++)
		window->draw(WoodBoard[i]);
	window->draw(Help);
	window->draw(Options);
	window->draw(Quit);
}

string MainMenuScreen::Update()
{
	//return "";
	return "StartGame";
}

