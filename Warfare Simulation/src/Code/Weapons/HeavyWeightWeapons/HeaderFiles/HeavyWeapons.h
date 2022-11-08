#ifndef HEAVYWEAPONS_H
#define HEAVYWEAPONS_H
#include "../../HeaderFiles/Weapons.h"

class HeavyWeapons : public Weapons
{
    public:
        HeavyWeapons(int, int, string);
        ~HeavyWeapons(){};
};

#endif