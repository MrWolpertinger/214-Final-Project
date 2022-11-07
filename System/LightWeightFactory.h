#ifndef LIGHTWEIGHTFACTORY_H
#define LIGHTWEIGHTFACTORY_H
#include "WeaponsFactory.h"


class LightWeightFactory : public WeaponsFactory
{
    public:
        LightWeightFactory(){};
        ~LightWeightFactory(){};
        Weapons* produceGrenades(int damage, int num);
        Weapons* produceMachineGuns(int damage, int num);
        Weapons* produceRifles(int damage, int num);
        Weapons* producePistols(int damage, int num);
     
};
#endif
