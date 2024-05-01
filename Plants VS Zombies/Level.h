#pragma once
#include "Screen.h"
class Level :public Screen
{
protected:
	string type;
	
public:
	//Level();
	virtual string Update() = 0;
	virtual void Draw() const = 0;
};

