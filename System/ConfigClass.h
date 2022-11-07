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

struct CountryStruct {
    std::string name;
    char side; //A||B||N
    int supportX;
    int NoOfWeapons[8];//0-grenades 1-MachineGuns 2-Rifels 3-pistols 4-Warships 5-Submarines 6-Tanks 7-Aircrafts
    int WeaponDMGX[8];
    int NumOfForces;// size of countriesForces[]+1
    Force* CountryForces;
};

class ConfigClass
{
public:
    CountryStruct* ListOfCountries;
    int ChangableX[3];
    int SizeOfArr;// size of ListOfCountries[]+1
    void ParseConfigFile(std::string path);
    static ConfigClass* instance();
protected:
    ConfigClass() {};
private: 
    static ConfigClass* onlyInstance_;
};

#endif//ConfigClass::ChangableX[0] = 