#include "ConfigClass.h"
#include "toml.hpp"
#include <iostream>

ConfigClass* ConfigClass::onlyInstance_;

ConfigClass* ConfigClass::instance() {
    if(ConfigClass::onlyInstance_ == nullptr) {
        ConfigClass::onlyInstance_ = new ConfigClass();
    }
    return ConfigClass::onlyInstance_;
};

void ConfigClass::ParseConfigFile(std::string path) {
    //check and remove if var is already saturated
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
    this->SizeOfArr = *tbl.at_path("CountryNumber").value<int>();
    this->ListOfCountries = new CountryStruct[this->SizeOfArr];// allocating memory for country structs

    for (int i = 0; i < this->SizeOfArr; i++) {
        this->ListOfCountries[i].NumOfForces = *tbl.at_path("Country" + std::to_string(i+1) + ".NumberOfForces").value<int>();
        int troopAlocated = 0;
        this->ListOfCountries[i].CountryForces = new Force[this->ListOfCountries[i].NumOfForces];
        for(int j = 0; (j < TotalTroops && troopAlocated < this->ListOfCountries[i].NumOfForces); j++) {
            if(f[j].Country == ("Country" + std::to_string(i+1))) {
                this->ListOfCountries[i].CountryForces[troopAlocated++] = f[i];
            }
        }
        //added Force structs to country structs
        std::string side = *tbl.at_path("Country" + std::to_string(i+1) + ".Side").value<std::string>();
        if(side == "A") {
            this->ListOfCountries[i].side = 'A';
        } else if(side == "B") {
            this->ListOfCountries[i].side = 'B';
        } else {
            this->ListOfCountries[i].side = 'N';
        }

        this->ListOfCountries[i].supportX = *tbl.at_path("Country" + std::to_string(i+1) + ".supportMultiplier").value<int>();

        for(int j = 0; j < 8; j++) {
            this->ListOfCountries[i].NoOfWeapons[j] =  *tbl.at_path("Country" + std::to_string(i+1) + ".NumberOfWeapons")[j].value<int>();
            this->ListOfCountries[i].WeaponDMGX[j] =  *tbl.at_path("Country" + std::to_string(i+1) + ".WeaponsMultiplier")[j].value<int>();
        }
    }
};