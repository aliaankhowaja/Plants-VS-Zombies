#pragma once
#include "Plant.h"
class Wallnut : public Plant
{
private:int upfd;
public:
	Wallnut(int row, int column);
	virtual void GetDamage();
	virtual void Act();
	virtual void Update();
};

