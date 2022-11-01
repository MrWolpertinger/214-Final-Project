#ifndef CONFIGCLASS_H
#define CONFIGCLASS_H
#include <string>
#include <iostream>

class ConfigClass
{
private:
    static int** MaxTroops;
    static int** InitialTroops;
    static double** DMG_Multipliers;
    static double** Health_multipliers;
    static int/*index*/** forceBelongsTo;

    static std::string** CountryNames;
    static bool** IsInGroupA;
    static bool** IsNeutral;
public:
    static void ParseConfigFile(std::string pathe);
};

#endif