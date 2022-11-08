#ifndef HEAVYWEIGHTFACTORY_H
#define HEAVYWEIGHTFACTORY_H
#include "WeaponsFactory.h"

class HeavyWeightFactory : public WeaponsFactory
{
    public:
        HeavyWeightFactory(){};
        ~HeavyWeightFactory(){};
        Weapons* produceWarships(int damage, int num);
        Weapons* produceTanks(int damage, int num);
        Weapons* produceSubmarines(int damage, int num);
        Weapons* produceHelicopters(int damage, int num);
};

#endif