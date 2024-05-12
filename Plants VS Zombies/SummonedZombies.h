#pragma once
#include "Zombie.h"
#include"DancingZombie.h"
class SummonedZombies :
    public Zombie
{
public:
    SummonedZombies(int x, int y);
    string Update();
    void Act();
   // SummonedZombies* GetZombie(bool ready,int x,int y);
};

