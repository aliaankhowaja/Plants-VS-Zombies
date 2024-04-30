#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1066, 600), "Plants VS Zombies");
	//screens;
	top = -1;
}
void Game::PushScreen(Screen& screen) {
	top++; // go one level up
	screens[top] = screen; // add the new screen to the top of the screen stack
}

void Game::PopScreen() {
	if (!top) return;//if no screen present
	top--;
}

sf::RenderWindow* Game::GetWindow() const
{
	return window;
}

Screen& Game::GetScreen()
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

void Game::draw()
{
	GetScreen().Draw();
}

void Game::update()
{
	GetScreen().Update();
}

void Game::run()
{
	sf::Sprite bg;
	sf::Texture bgT;
	bgT.loadFromFile("Images/titlescreen.jpg");
	bg.setTexture(bgT);
	Screen screen(window, bg);
	PushScreen(screen);
	sf::Event e;
	while (window->isOpen()) {
		
		update();
		draw();
		while (window->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				return;
			}
		}
		window->display();
		window->clear();

	}
}
