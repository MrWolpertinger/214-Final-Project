#ifndef TANKS_H
#define TANKS_H
#include "HeavyWeapons.h"

class Tanks : public HeavyWeapons
{
    public:
        Tanks(int, int,string);
        ~Tanks(){};
};

#endif