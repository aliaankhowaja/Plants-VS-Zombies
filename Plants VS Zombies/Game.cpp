#include "Game.h"
#include "LoadingScreen.h"
#include "MainMenuScreen.h"
#include"HelpScreen.h"
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
	//sf::Sprite bg;
	//sf::Texture bgT;
	//bgT.loadFromFile("Resources/Images/titlescreen.jpg");
	//bg.setTexture(bgT);
	//Screen screen(window, bg);
	//PushScreen(screen);
	Screen *loadingScreen = new LoadingScreen(window);
	PushScreen(loadingScreen);
	sf::Event e;
	while (window->isOpen()) {
		
		string command = Update();
		if (command == "LoadingComplete") ShowMainMenu();
		else if (command == "StartGame") ShowGameScreen();
		Draw();
		while (window->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				return;
			}
		}
		window->display();
		window->clear();

	}
}

void Game::ShowMainMenu()
{
	Screen* mainMenu = new MainMenuScreen(window);
	PopScreen();
	PushScreen(mainMenu);
}

void Game::ShowGameScreen() {
	Screen* level1 = new MainMenuScreen(window);
	//PopScreen();
	//PushScreen(level1);
}
