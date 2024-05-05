#pragma once
#include "Plant.h"
class SunFlower : public Plant
{
private:int upfd;
public:
	SunFlower(int row, int column);
	virtual void GetDamage();
	virtual void Act();
	virtual void Update();
};

