#ifndef LIGHTWEAPONS_H
#define LIGHTWEAPONS_H
#include "../../HeaderFiles/Weapons.h"

/// @brief 
class LightWeapons : public Weapons
{
    public: 
        LightWeapons(int, int, string);
        ~LightWeapons(){};
};

#endif