#pragma once
#include "Plant.h"
class CherryBomb : public Plant
{
private:int upfd;
public:
	CherryBomb(int row, int column);
	virtual void GetDamage();
	virtual void Act();
	virtual void Update();
};

