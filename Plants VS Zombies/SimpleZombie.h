#pragma once
#include "Zombie.h"
class SimpleZombie :
    public Zombie
{
public:
    SimpleZombie(int row);
    virtual void Update();
    //virtual void GetDps();
    virtual void Act();
};

