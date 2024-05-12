#pragma once
#include "Plant.h"
#include "PeaShooter.h"
class Repeater : public PeaShooter
{

public:
	Repeater(int row, int column);
	virtual void GetDamage();
	virtual bool Act();
	virtual void Update();
};

