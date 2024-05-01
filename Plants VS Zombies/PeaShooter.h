#pragma once
#include "Plant.h"
class PeaShooter : public Plant {
protected:
	bool shooting;
public:
	virtual void Shoot();
	virtual void GetDamage();
	virtual void Act();
	virtual void Update();
};

