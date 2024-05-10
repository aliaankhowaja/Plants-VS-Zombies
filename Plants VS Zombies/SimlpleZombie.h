#pragma once
#include "Zombie.h"
class SimlpleZombie :
    public Zombie
{
public:
    SimlpleZombie();
    virtual void Update();
    virtual void GetDps();
    virtual void Act();
};

