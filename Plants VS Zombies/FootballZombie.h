#pragma once
#include "Zombie.h"
class FootballZombie :
    public Zombie
{
public:
    FootballZombie();
    virtual void Update();
    virtual void Act();
    virtual void GetDps();
};

