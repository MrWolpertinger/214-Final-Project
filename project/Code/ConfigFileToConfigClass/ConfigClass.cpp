#include "ConfigClass.h"
#include "TOMLParser/toml.hpp"
#include <iostream>

Country* ConfigClass::ListOfCountries;
int ConfigClass::wartheatreRange[2];

void ConfigClass::ParseConfigFile(std::string path) {
    toml::table tbl;
    try
    {
        tbl = toml::parse_file(path);
    }
    catch (const toml::parse_error& err)
    {
        std::cerr << "Parsing failed:\n" << err << "\n";
    }
    
    //make troops structs first in an array to be copied into the individual country objects
    int TotalTroops = *tbl["Totaltroops"].value<int>();
    Force f[TotalTroops];

    for(int i = 0; i < TotalTroops; i++) {
        f[i].DMGX = *tbl.at_path(("Force" + std::to_string(i+1) + ".DMGX")).value<int>();
        f[i].HPX = *tbl.at_path(("Force" + std::to_string(i+1) + ".HPX")).value<int>();
        f[i].MaxTroops = *tbl.at_path(("Force" + std::to_string(i+1) + ".maxTroops")).value<int>();
        f[i].Troops = *tbl.at_path(("Force" + std::to_string(i+1) + ".initTroops")).value<int>();
        f[i].Country = *tbl.at_path(("Force" + std::to_string(i+1) + ".country")).value<std::string>();
        f[i].Type = *tbl.at_path(("Force" + std::to_string(i+1) + ".type")).value<std::string>();
    }

    //create and populate country
    int NumOfCountries = *tbl["CountryNumber"].value<int>();
    ConfigClass::ListOfCountries = new Country[NumOfCountries];// allocating memory for country structs

    for (int i = 0; i < NumOfCountries; i++) {
        int NumOfTroops = *tbl[("Country" + i)]["NumberOfForces"].value<int>();
        ConfigClass::ListOfCountries[i].countriesForces = new Force[NumOfTroops];
        
    }
};