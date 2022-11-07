#include "CountryStrategy.h"
#include<iostream>

using namespace std ;

/**
 * @brief Destructor of the CountryStrategy class.
*/
CountryStrategy::~CountryStrategy(){}

/**
 * @brief Destructor of the Aggresive class.
*/
Aggresive::~Aggresive(){
    cout<<"Deconstructing Aggresive Strategy\n " ;
}

/**
 * @brief Destructor of the Defensive class.
*/
Defensive::~Defensive(){
    cout<<"Deconstructing Defensive Strategy\n " ;
}

/**
 * @brief Destructor of the Supportive class.
*/
Supportive::~Supportive(){
    cout<<"Deconstructing Supportive Strategy\n " ;
}

/**
 * @brief A getter for the country strategy.
 * @return A string message containing the strategy of the country.
*/
string Aggresive::getCountryStrategy(){
   
    return "Aggrasive Strategy";
}

/**
 * @brief A getter for the country strategy.
 * @return A string message containing the strategy of the country.
*/
string Defensive::getCountryStrategy(){
    
    return "Defensive Strategy";
}

/**
 * @brief A getter for the country strategy.
 * @return A string message containing the strategy of the country.
*/
string Supportive::getCountryStrategy(){
    
    return "Supportive Strategy";
}
