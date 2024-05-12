#pragma once
#include "Zombie.h"
class SimpleZombie :
    public Zombie
{
public:
    SimpleZombie(int row);
    virtual string Update();
    //virtual void GetDps();
    virtual void Act();
    void GetDamage(int x);
};

