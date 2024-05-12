#pragma once
#include "Zombie.h"
class FootballZombie :
    public Zombie
{
private:
    sf::Clock movementC;
public:
    FootballZombie(int row);
    virtual void Update();
    virtual void Act();
   
    //virtual void GetDps();
};

