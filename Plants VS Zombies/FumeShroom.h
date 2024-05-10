#pragma once
#include "Plant.h"
class FumeShroom : public Plant
{
private:int upfd;
public:
	FumeShroom(int row, int column);
	virtual void GetDamage();
	virtual bool Act();
	virtual void Update();
};

