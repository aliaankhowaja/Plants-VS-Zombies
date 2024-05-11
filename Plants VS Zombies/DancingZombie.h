#pragma once
#include "Zombie.h"
class DancingZombie :
    public Zombie
{

public:
   DancingZombie();
   virtual void Update();
   virtual void Act();
   virtual void GetDps();
};

