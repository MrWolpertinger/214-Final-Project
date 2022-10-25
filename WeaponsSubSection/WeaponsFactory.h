#ifndef WEAPONSFACTORY_H
#define WEAPONSFACTORY_H
#include "LightWeapons.h"

class WeaponsFactory
{
    public:
        Weapons* produceWeapons();
        WeaponsFactory();
        ~WeaponsFactory(){};
};

#endif