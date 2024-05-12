#pragma once
#include "Zombie.h"
class FlyingZombie :
    public Zombie
{
public:
    FlyingZombie(int row);
    virtual void Update();
    virtual void Act();
    void GetDamage(int x);
    //virtual void GetDps();
};

