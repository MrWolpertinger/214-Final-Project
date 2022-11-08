#include "ConfigClass.h"
#include "toml.hpp"
#include <iostream>


ConfigClass::~ConfigClass() {
    delete [] this->ListOfCountries;
};

ConfigClass* ConfigClass::onlyInstance_;

ConfigClass* ConfigClass::instance() {
    if(ConfigClass::onlyInstance_ == nullptr) {
        ConfigClass::onlyInstance_ = new ConfigClass();
    }
    return ConfigClass::onlyInstance_;
    srand(time(NULL));
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
        return;
    }
    
    //make troops structs first in an array to be copied into the individual country objects
    try {
    int TotalTroops = *tbl.at_path("Totaltroops").value<int>();
    
    //create and populate country
    this->SizeOfArr = *tbl.at_path("CountryNumber").value<int>();
    this->ListOfCountries = new CountryStruct[this->SizeOfArr];// allocating memory for country structs

    for (int i = 0; i < this->SizeOfArr; i++) {

        this->ListOfCountries[i].NumOfForces = *tbl.at_path("Country" + std::to_string(i+1) + ".NumberOfForces").value<int>();//get size of array
        //this->ListOfCountries[i].CountryForces = new Force[this->ListOfCountries[i].NumOfForces];// allocate array

        for(int j = 0; j < this->ListOfCountries[i].NumOfForces; j++) {//add a random troop to country
            int x = (rand() % TotalTroops);
            this->ListOfCountries[i].CountryForces[j].DMGX = *tbl.at_path(("Force" + std::to_string(x) + ".DMGX")).value<int>();
            this->ListOfCountries[i].CountryForces[j].HPX = *tbl.at_path(("Force" + std::to_string(x) + ".HPX")).value<int>();
            this->ListOfCountries[i].CountryForces[j].Troops = *tbl.at_path(("Force" + std::to_string(x) + ".initTroops")).value<int>();
            this->ListOfCountries[i].CountryForces[j].Type = *tbl.at_path(("Force" + std::to_string(x) + ".type")).value<std::string>();
        }

        this->ListOfCountries[i].supportX = *tbl.at_path("Country" + std::to_string(i+1) + ".supportMultiplier").value<int>();
        this->ListOfCountries[i].TotalSpending = *tbl.at_path("Country" + std::to_string(i+1) + ".totalSpending").value<double>();

        this->ListOfCountries[i].name = *tbl.at_path("Country" + std::to_string(i+1) + ".Name").value<std::string>();
        this->ListOfCountries[i].leaderName = *tbl.at_path("Country" + std::to_string(i+1) + ".Leader").value<std::string>();

        for(int j = 0; j < 8; j++) {
            this->ListOfCountries[i].NoOfWeapons[j] =  *tbl.at_path("Country" + std::to_string(i+1) + ".NumberOfWeapons")[j].value<int>();
            this->ListOfCountries[i].WeaponDMGX[j] =  *tbl.at_path("Country" + std::to_string(i+1) + ".WeaponsMultiplier")[j].value<int>();
            this->ListOfCountries[i].CountryStats[j] = *tbl.at_path("Country" + std::to_string(i+1) + ".CountryStats")[j].value<int>();
        }
    }
    } catch (const std::bad_alloc& e) {
        std::cout << e.what() << std::endl;
    }
};

CountryStruct* ConfigClass::getUniqueCountry() {
    bool found = false;
    for(int i = 0; i < this->SizeOfArr; i++) {
        if(this->ListOfCountries[i].HasBeenUsed == false) {
            found = true;
        }
    }
    if (found == false) {
        return nullptr;
    }
    
    while(found == true) {
        int x = rand() % this->SizeOfArr;
        if(this->ListOfCountries[x].HasBeenUsed == false) {
            this->ListOfCountries[x].HasBeenUsed = true;
            return &this->ListOfCountries[x];
        }
    }
    return nullptr;
};