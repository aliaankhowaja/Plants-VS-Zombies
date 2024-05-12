#pragma once
//#include "Graphics.h"
#include "Screen.h"
class Game
{
public:
private:
	sf::RenderWindow* window;
	Screen* screens[100];
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
	string Update();
	void Run();
	void ShowMainMenu();
	void ShowGameScreen(int level);
	void ShowRewardScreen(int reward);
	void ShowHelp();
};

