#ifndef CONFIGCLASS_H
#define CONFIGCLASS_H
#include <string>

struct Force {
    int DMGX;
    int HPX;
    int Troops;// current size of dynamic arr
    std::string Type;
};

struct CountryStruct {
    std::string name;
    std::string leaderName;
    int supportX;
    int NoOfWeapons[8];//0-grenades 1-MachineGuns 2-Rifels 3-pistols 4-Warships 5-Submarines 6-Tanks 7-Aircrafts
    int WeaponDMGX[8];
    int CountryStats[8];//0-refugeeCount 1-enlistedCitizens 2-deployedCitizens 3-fightingCitizens
    double TotalSpending;//4-stationaryCitizens 5-returnedCitizens 6-deathtoll 7-unlistedCitizens
    int NumOfForces;// size of countriesForces[]+1
    Force CountryForces[25];//max number of forces cannot exceed 25
    bool HasBeenUsed = false;
};

class ConfigClass
{
public:
    CountryStruct* ListOfCountries;
    int ChangableX[3];
    int SizeOfArr;// size of ListOfCountries[]+1
    void ParseConfigFile(std::string path);
    static ConfigClass* instance();
    CountryStruct* getUniqueCountry();//returns nullptr if countryarr has been exhausted
protected:
    ConfigClass() {};
    ~ConfigClass();
private: 
    static ConfigClass* onlyInstance_;
};

#endif