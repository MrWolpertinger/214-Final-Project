#ifndef MACHINEGUNS_H
#define MACHINEGUNS_H
#include "LightWeapons.h"


class MachineGuns : public LightWeapons
{
    public:
        MachineGuns(int, int, string);
        ~MachineGuns(){};
};

#endif