#ifndef PISTOLS_H
#define PISTOLS_H
#include "LightWeapons.h"

class Pistols : public LightWeapons
{
    public:
        Pistols(int,int, string);
        ~Pistols(){};
};

#endif