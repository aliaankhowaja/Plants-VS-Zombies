#pragma once
#include "Zombie.h"
#include "SummonedZombies.h"
class DancingZombie :
    public Zombie
{
private:
    sf::Clock movementC;
    sf::Clock SummonClock;
   // SummonedZombies* Summoned;
   
public:
   DancingZombie(int row);
   virtual string Update();
   virtual void Act();
   void summon();
};

