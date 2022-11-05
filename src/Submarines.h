#ifndef SUBMARINES_H
#define SUBMARINES_H
#include "HeavyWeapons.h"

class Submarines : public HeavyWeapons
{
    public:
        Submarines(int, int, string);
        ~Submarines(){};
};

#endif