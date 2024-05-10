#pragma once
#include "Plant.h"
class Repeater : public Plant
{
private:int upfd;
public:
	Repeater(int row, int column);
	virtual void GetDamage();
	virtual bool Act();
	virtual void Update();
};

