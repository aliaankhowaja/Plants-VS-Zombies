#pragma once
#include "Zombie.h"
class FlyingZombie :
    public Zombie
{
public:
    FlyingZombie(int row);
    virtual string Update();
    virtual void Act();
    
    //virtual void GetDps();
};

