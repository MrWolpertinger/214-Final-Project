#include "ConfigClass.h"
#include "TOMLParser/toml.hpp"
#include <iostream>

Country* ConfigClass::ListOfCountries;
int ConfigClass::SizeOfArr;
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
    int TotalTroops = *tbl.at_path("Totaltroops").value<int>();
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
    ConfigClass::SizeOfArr = *tbl.at_path("CountryNumber").value<int>();
    ConfigClass::ListOfCountries = new Country[ConfigClass::SizeOfArr];// allocating memory for country structs

    for (int i = 0; i < ConfigClass::SizeOfArr; i++) {
        ConfigClass::ListOfCountries[i].NumOfForces = *tbl.at_path("Country" + std::to_string(i+1) + ".NumberOfForces").value<int>();
        int troopAlocated = 0;
        ConfigClass::ListOfCountries[i].countryForces = new Force[ConfigClass::ListOfCountries[i].NumOfForces];
        for(int j = 0; (j < TotalTroops && troopAlocated < ConfigClass::ListOfCountries[i].NumOfForces); j++) {
            if(f[j].Country == ("Country" + std::to_string(i+1))) {
                ConfigClass::ListOfCountries[i].countryForces[troopAlocated++] = f[i];
            }
        }
        //added Force structs to country structs
        std::string side = *tbl.at_path("Country" + std::to_string(i+1) + ".Side").value<std::string>();
        if(side == "A") {
            ConfigClass::ListOfCountries[i].side = 'A';
        } else if(side == "B") {
            ConfigClass::ListOfCountries[i].side = 'B';
        } else {
            ConfigClass::ListOfCountries[i].side = 'N';
        }

        ConfigClass::ListOfCountries[i].supportX = *tbl.at_path("Country" + std::to_string(i+1) + ".supportMultiplier").value<int>();

        for(int j = 0; j < 8; j++) {
            ConfigClass::ListOfCountries[i].NoOfWeapons[j] =  *tbl.at_path("Country" + std::to_string(i+1) + ".NumberOfWeapons")[j].value<int>();
            ConfigClass::ListOfCountries[i].WeaponDMGX[j] =  *tbl.at_path("Country" + std::to_string(i+1) + ".WeaponsMultiplier")[j].value<int>();
        }
    }
};