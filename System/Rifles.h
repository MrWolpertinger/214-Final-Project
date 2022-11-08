#ifndef RIFLES_H
#define RIFLES_H
#include "LightWeapons.h"

class Rifles : public LightWeapons
{
    public:
        Rifles(int,int, string);
        ~Rifles(){};
};

#endif