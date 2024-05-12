#include "Game.h"
#include "LoadingScreen.h"
#include "MainMenuScreen.h"
#include"HelpScreen.h"
#include"QuitScreen.h"
#include "BeginnersGarden.h"
#include "NewPlayerInput.h"
#include "PausedGame.h"
#include"RewardScreen.h"
#include <iostream>
#include <fstream>
#include "ZombieOutskirts.h"
#include "SunFlowerFields.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 600), "Plants VS Zombies");
	//screens;
	top = -1;
}
void Game::PushScreen(Screen *screen) {
	top++; // go one level up
	screens[top] = screen; // add the new screen to the top of the screen stack
}

void Game::PopScreen() {
	if (top+1) return;//if no screen present
	delete screens[top];
	top--;
}

sf::RenderWindow* Game::GetWindow() const
{
	return window;
}

Screen* Game::GetScreen()
{
	return screens[top];
	// TODO: insert return statement here
}

void Game::CloseGame()
{
	delete this;
}

Game::~Game()
{
	window->close();
	/*while (top + 1) {
		
	}*/
}

void Game::Draw()
{
	GetScreen()->Draw();
}

string Game::Update()
{
	return GetScreen()->Update();
}

void Game::Run()
{
	Screen *loadingScreen = new LoadingScreen(window);
	PushScreen(loadingScreen);
	//ShowMainMenu();

	
	//ShowGameScreen();
	
	sf::Event e;
	while (window->isOpen()) {
		
		string command = Update();
		if (command == "LoadingComplete") ShowMainMenu();
		else if (command == "Beginners Garden Compelete") ShowRewardScreen(1);
		else if (command == "level1") ShowGameScreen(1);
		else if (command == "Zombie Outskirts Compelete") ShowRewardScreen(2);
		else if (command == "level2") ShowGameScreen(2);
		else if (command == "SunFlower Fields Compelete") ShowRewardScreen(3);
		else if (command == "level3") ShowGameScreen(3);
		else if (command == "gameOver") ShowMainMenu();
		else if (command == "help")ShowHelp();

		while (window->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				return;
			}
		}
		window->clear();
		Draw();
		window->display();
	}
}

void Game::ShowMainMenu()
{
	Screen* mainMenu = new MainMenuScreen(window);
	PopScreen();
	PushScreen(mainMenu);
}

void Game::ShowGameScreen(int level) {
	Screen* gameLevel;
	switch (level) {
		case 1:
			gameLevel = new BeginnersGarden(window);
			//PopScreen();
			PushScreen(gameLevel);
			break;
		case 2:
			gameLevel = new ZombieOutskirts(window);
			//PopScreen();
			PushScreen(gameLevel);
			break;
		case 3:
			gameLevel = new SunFlowerFields(window);
			//PopScreen();
			PushScreen(gameLevel);
			break;

	}

}

void Game::ShowRewardScreen(int reward)
{
	Screen* screen;
	switch (reward) {
	case 1:
		screen = new RewardScreen(1, window);
		PopScreen();
		PushScreen(screen);
		break;
	case 2:
		screen = new RewardScreen(2, window);
		PopScreen();
		PushScreen(screen);
		break;
	case 3:
		screen = new RewardScreen(3, window);
		PopScreen();
		PushScreen(screen);
		break;

	}
}

void Game::ShowHelp()
{
	Screen* help = new HelpScreen(window);
	PushScreen(help);
}
