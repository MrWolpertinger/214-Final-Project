#ifndef LIGHTWEAPONS_H
#define LIGHTWEAPONS_H
#include "../Weapons.h"

class LightWeapons : public Weapons
{
    public:
        LightWeapons(){};
        LightWeapons(int,string);
        ~LightWeapons(){};
};

#endif