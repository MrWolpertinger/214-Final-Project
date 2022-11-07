/**
 * @file WeaponsFactory_H. It is a base class for the Weapon factories.
*/
#ifndef WEAPONSFACTORY_H
#define WEAPONSFACTORY_H
#include "WeaponsInclude.h"

class WeaponsFactory
{
    public:
        /**
         * @brief Constructor of the WeaponFactory.
        */
        WeaponsFactory(){};
        
        /**
         * @brief A virtual destroctor of the WeaponFactory.
        */
        virtual ~WeaponsFactory(){};
};

#endif
