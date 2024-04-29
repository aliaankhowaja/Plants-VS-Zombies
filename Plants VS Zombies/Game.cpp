#include "Game.h"

Game::Game()
{
	//screens;
	top = -1;
}
void Game::PushScreen(Screen &screen) {
	top++;
	screens[top] = screen;
}

Game::~Game()
{
	while (top + 1) {
		delete[] screens;
	}
}

void Game::pushScreen(Screen)
{
}
