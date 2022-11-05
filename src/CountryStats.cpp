#include "CountryStats.h"

void CountryStats::print(){
    cout << "Country Military Expenditure: " << this->totalMilitarySpending << "\n";
    cout << "Unlisted Citizens: " << this->unlistedCitizens << "\n";
    cout << "Deployed Citizens: " << this->deployedCitizens << "\n";
    cout << "Fighting Citizens: " << this->fightingCitizens << "\n";
    cout << "Stationed Citizens: " << this->stationedCitizens << "\n";
    cout << "Returned Citizens: " << this->returnedCitizens << "\n";
    cout << "Death Count: " << this->deathtoll << "\n";
    cout << "===================================================================\n";
}

int CountryStats::getRefugee(){
    return this->refugeeCount;
}

int CountryStats::getUnlisted(){
    return this->unlistedCitizens;
}

int CountryStats::getEnlisted(){
    return this->enlistedCitizens;
}

int CountryStats::getDeployed(){
    return this->deployedCitizens;
}

int CountryStats::getFighting(){
    return this->deployedCitizens;
}

int CountryStats::getStationed(){
    return this->stationedCitizens;
}

int CountryStats::getReturned(){
    return this->returnedCitizens;
}

int CountryStats::getDeath(){
    return this->deathtoll;
}

long CountryStats::getBudget(){
    return this->totalMilitarySpending;
}

void CountryStats::setRefugee(int x){
    this->refugeeCount = x;
}

void CountryStats::setUnlisted(int x){
    this->unlistedCitizens = x;
}

void CountryStats::setEnlisted(int x){
    this->enlistedCitizens = x;
}

void CountryStats::setDeployed(int x){
    this->deployedCitizens = x;
}

void CountryStats::setFighting(int x){
    this->fightingCitizens = x;
}

void CountryStats::setStationed(int x){
    this->stationedCitizens = x;
}

void CountryStats::setReturned(int x){
    this->returnedCitizens = x;
}

void CountryStats::setDeath(int x){
    this->deathtoll = x;
}

void CountryStats::setBudget(long x){
    this->totalMilitarySpending = x;
}