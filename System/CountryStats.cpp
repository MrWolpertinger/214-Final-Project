#include "CountryStats.h"

/**
 * @brief Destructor of the CountryStats class.
 * @param filepath filepath contain the data about a country.
*/
CountryStats::CountryStats(){

}

/**
 * @brief Destructor of this CountryStats class.
*/
CountryStats::~CountryStats(){}

/**
 * @brief prints the background statistics of the country during the war.
*/
void CountryStats::print(){
    cout << "Country Military Expenditure: " << this->totalMilitarySpending << "\n";
    cout << "Unlisted Citizens: " << this->unlistedCitizens << "\n";
    cout << "Deployed Citizens: " << this->deployedCitizens << "\n";
    cout << "Fighting Citizens: " << this->fightingCitizens << "\n";
    cout << "Stationed Citizens: " << this->stationedCitizens << "\n";
    cout << "Returned Citizens: " << this->returnedCitizens << "\n";
    cout << "Refugees Count: " << this->refugeeCount << "\n";
    cout << "Death Count: " << this->deathtoll << "\n";
    cout << "===================================================================\n";
}

/**
 * @brief Getter for the refugeeCount. Returns the number of refugees in a country.
 * @return refugeeCount.
*/
int CountryStats::getRefugee(){
    return this->refugeeCount;
}

/**
 * @brief Getter for the unlistedCitizens. Returns the number of unlisted citizens after the war. 
 * @return unlistedCitizens.
*/
int CountryStats::getUnlisted(){
    return this->unlistedCitizens;
}

/**
 * @brief Getter for the enlistedCitizens. Returns the number of enlisted Citizens after the war. 
 * @return enlistedCitizens.
*/
int CountryStats::getEnlisted(){
    return this->enlistedCitizens;
}

/**
 * @brief Getter for the deployedCitizens. Returns the number of deployed Citizens to fight the war.
 * @return deployedCitizens.
*/
int CountryStats::getDeployed(){
    return this->deployedCitizens;
}

/**
 * @brief Getter for the fightingCitizens. Returns the number of deployed Citizens fighting the war.
 * @return fightingCitizens.
*/
int CountryStats::getFighting(){
    return this->fightingCitizens;
}

/**
 * @brief Getter for the stationedCitizens. Returns the number of stationed Citizens of a in the country.
 * @return stationedCitizens.
*/
int CountryStats::getStationed(){
    return this->stationedCitizens;
}

/**
 * @brief Getter for the returnedCitizens. Returns the number of returned citizens after a war.
 * @return returnedCitizens.
*/
int CountryStats::getReturned(){
    return this->returnedCitizens;
}

/**
 * @brief Getter for the deathtoll. Returns the number of deaths in a country.
 * @return deathtoll.
*/
int CountryStats::getDeath(){
    return this->deathtoll;
}

/**
 * @brief Getter for the totalMilitarySpending. Returns the budget a country has for Military.
 * @return totalMilitarySpending.
*/
long CountryStats::getBudget(){
    return this->totalMilitarySpending;
}

/**
 * @brief Setter for the number of refugees.
 * @param x
*/
void CountryStats::setRefugee(int x){
    this->refugeeCount = x;
}

/**
 * @brief Setter for unlistedCitizens.
 * @param x
*/
void CountryStats::setUnlisted(int x){
    this->unlistedCitizens = x;
}

/**
 * @brief Setter for enlistedCitizens.
 * @param x
*/
void CountryStats::setEnlisted(int x){
    this->enlistedCitizens = x;
}

/**
 * @brief Setter for deployedCitizens .
 * @param x
*/
void CountryStats::setDeployed(int x){
    this->deployedCitizens = x;
}

/**
 * @brief Setter for fightingCitizens.
 * @param x
*/
void CountryStats::setFighting(int x){
    this->fightingCitizens = x;
}

/**
 * @brief Setter for stationedCitizens.
 * @param x
*/
void CountryStats::setStationed(int x){
    this->stationedCitizens = x;
}

/**
 * @brief Setter for returnedCitizens.
 * @param x
*/
void CountryStats::setReturned(int x){
    this->returnedCitizens = x;
}

/**
 * @brief Setter for deathtoll. Sets the number of deaths of a country.
 * @param x
*/
void CountryStats::setDeath(int x){
    this->deathtoll = x;
}

/**
 * @brief Setter for the totalMilitarySpending. sets the total military budget.
 * @param x
*/
void CountryStats::setBudget(long x){
    this->totalMilitarySpending = x;
}