#pragma once
#include "Screen.h"
class Game
{
	Screen screens[10];
	int top ;
public:
	Game();
	void PushScreen(Screen &screen);
	void PopScreen();
	Screen& GetScreen(); // returns the topmost Screen
	~Game();
};


