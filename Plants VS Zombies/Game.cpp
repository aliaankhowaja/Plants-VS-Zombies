#include "Game.h"
#include "LoadingScreen.h"
#include "MainMenuScreen.h"
#include"HelpScreen.h"
#include "BeginnersGarden.h"
#include <iostream>

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
	//PushScreen(loadingScreen);
	ShowGameScreen();

	sf::Event e;
	while (window->isOpen()) {
		
		string command = Update();
		//if (command == "LoadingComplete") ShowMainMenu();
		//else if (command == "StartGame") ShowGameScreen();
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

void Game::ShowGameScreen() {
	Screen* level1 = new BeginnersGarden(window);
	//PopScreen();
	PushScreen(level1);
}
