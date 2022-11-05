#ifndef GRENADES_H
#define GRENADES_H
#include "LightWeapons.h"

class Grenades : public LightWeapons
{
    public:
        Grenades(int, int, string);
        ~Grenades(){};
};

#endif