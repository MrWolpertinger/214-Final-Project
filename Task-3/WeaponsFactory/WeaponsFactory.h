#ifndef WEAPONSFACTORY_H
#define WEAPONSFACTORY_H

#include "../Weapons.h"
class WeaponsFactory
{
    public:
        virtual Weapons* produceWeapons(int choice, int num, int budget) = 0;
        WeaponsFactory(){};
        ~WeaponsFactory(){};
};

#endif