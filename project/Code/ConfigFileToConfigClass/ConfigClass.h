#ifndef CONFIGCLASS_H
#define CONFIGCLASS_H
#include <string>

struct Force {
    int DMGX;
    int HPX;
    int MaxTroops;
    int Troops;
    std::string Country;
    std::string Type;
};

struct Country {
    std::string name;
    char side; //A||B||N
    int supportX;
    int NoOfWeapons[8];//0-grenades 1-MachineGuns 2-Rifels 3-pistols 4-Warships 5-Submarines 6-Tanks 7-Aircrafts
    int WeaponDMGX[8];
    Force* countriesForces;
};

class ConfigClass
{
public:
    static Country* ListOfCountries;
    static int wartheatreRange[2];

    static void ParseConfigFile(std::string path);
};

#endif