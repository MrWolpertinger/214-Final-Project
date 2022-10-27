#ifndef HEAVYWEAPONS_H
#define HEAVYWEAPONS_H
#include "../Weapons.h"

class HeavyWeapons : public Weapons
{
    public:
        HeavyWeapons(){};
        HeavyWeapons(int);
        ~HeavyWeapons(){};
};

#endif