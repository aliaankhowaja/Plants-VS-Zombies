#pragma once
#include "Plant.h"
class SnowPea : public Plant
{
private:int upfd;
public:
	SnowPea(int row, int column);
	virtual void GetDamage();
	virtual void Act();
	virtual void Update();
};

