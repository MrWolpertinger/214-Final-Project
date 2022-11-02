#ifndef CONFIGCLASS_H
#define CONFIGCLASS_H
#include <string>

struct Force {
    int DMGX;
    int HPX;
    int MaxTroops;
    int Troops;// current size of dynamic arr
    std::string Country;
    std::string Type;
};

struct Country {
    std::string name;
    char side; //A||B||N
    int supportX;
    int NoOfWeapons[8];//0-grenades 1-MachineGuns 2-Rifels 3-pistols 4-Warships 5-Submarines 6-Tanks 7-Aircrafts
    int WeaponDMGX[8];
    int NumOfForces;// size of countriesForces[]+1
    Force* countryForces;
};

class ConfigClass
{
public:
    static Country* ListOfCountries;
    static int wartheatreRange[2];
    static int SizeOfArr;// size of ListOfCountries[]+1
    static void ParseConfigFile(std::string path);
};

#endif