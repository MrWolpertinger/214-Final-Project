#ifndef LIGHTWEIGHTFACTORY_H
#define LIGHTWEIGHTFACTORY_H
#include "WeaponsFactory.h"


class LightWeightFactory : public WeaponsFactory
{
    public:
        Weapons* produceWeapons(int choice, int num, int budget);
        LightWeightFactory(){};
        ~LightWeightFactory(){};
};

#endif