#pragma once
#include "Plant.h"
class PeaShooter : public Plant {
protected:
	bool shooting;
public:
	PeaShooter(int row, int col);
	virtual void Shoot();
	virtual void GetDamage();
	virtual bool Act();
	virtual void Update();
	bool IsShooting();
};

