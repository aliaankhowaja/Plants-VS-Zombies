#pragma once
#include <iostream>
using namespace std;

class Players
{
private:
	string name;
	int score;
public:
	Players();
	Players(const Players& Player1);
	void setPlayerName(string name);
	void setScore(int score);
	string getPlayerName();
	int getScore();
	bool comparePlayerss(const Players& p1, const Players& p2);
};

