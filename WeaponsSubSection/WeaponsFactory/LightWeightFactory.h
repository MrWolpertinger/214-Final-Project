#ifndef LIGHTWEIGHTFACTORY_H
#define LIGHTWEIGHTFACTORY_H
#include "WeaponsFactory.h"
#include "../Weapons.h"

class LightWeightFactory : public WeaponsFactory
{
    public:
        Weapons* produceWeapons(int choice);
        LightWeightFactory(){};
        ~LightWeightFactory(){};
};

#endif