#ifndef WARSHIPS_H
#define WARSHIPS_H
#include "HeavyWeapons.h"

class Warships : public HeavyWeapons
{
    public:
        Warships(int, int, string);
        ~Warships(){};
};

#endif