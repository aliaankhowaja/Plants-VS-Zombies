#include "Players.h"

Players::Players()
{
	score = 0;
	name = "";
}

Players::Players(const Players& Player1)
{
	score = Player1.score;
	name = Player1.name;

}

void Players::setPlayerName(string name)
{
	this->name = name;
}

void Players::setScore(int score)
{
	this->score = score;
}

string Players::getPlayerName()
{
	return this->name;
}

int Players::getScore()
{
	return score;
}


