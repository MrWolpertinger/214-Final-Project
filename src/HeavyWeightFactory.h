#ifndef HEAVYWEIGHTFACTORY_H
#define HEAVYWEIGHTFACTORY_H
#include "WeaponsFactory.h"
#include "Weapons.h"

class HeavyWeightFactory : public WeaponsFactory
{
    public:
        Weapons* produceWeapons(int choice, int num, int budget);
        HeavyWeightFactory(){};
        ~HeavyWeightFactory(){};
};

#endif