#pragma once
#include "Zombie.h"
class DancingZombie :
    public Zombie
{

public:
   DancingZombie(int row);
   virtual void Update();
   virtual void Act();
   //virtual void GetDps();
};

