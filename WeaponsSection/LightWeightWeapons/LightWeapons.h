#ifndef LIGHTWEAPONS_H
#define LIGHTWEAPONS_H
#include "../Weapons.h"

/// @brief 
class LightWeapons : public Weapons
{
    public:
        LightWeapons(){};  
        LightWeapons(int,string);
        ~LightWeapons(){};
};

#endif