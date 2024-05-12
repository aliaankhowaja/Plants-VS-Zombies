#pragma once
#include "Zombie.h"
class SummonedZombies :
    public Zombie
{
public:
    SummonedZombies(int x, int y);
    string Update();
    void Act();
};

