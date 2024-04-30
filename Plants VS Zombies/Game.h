#pragma once
//#include "Graphics.h"
#include "Screen.h"
class Game
{
public:
private:
	sf::RenderWindow* window;
	Screen* screens[10];
	int top;

public:
	Game();
	~Game();
	void PushScreen(Screen *screen); // push a screen to the top of the stack
	void PopScreen(); // removes the screen from the top of the stack
	sf::RenderWindow* GetWindow() const;
	Screen* GetScreen(); // returns the top most Screen
	void CloseGame();
	void Draw();
	void Update();
	void Run();
};

