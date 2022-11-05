#ifndef HELICOPTERS_H
#define HELICOPTERS_H
#include "HeavyWeapons.h"

class Helicopters : public HeavyWeapons
{
    public:
        Helicopters(int, int, string);
        ~Helicopters(){};
};

#endif