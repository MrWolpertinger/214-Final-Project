#include "HeaderFiles/Sea_War_Theatre.h"

/**
 * @brief The copy constructor of the Sea_War_Theatre class. Copy the attribute of another objects.
 * @param Template [Sea_War_Theatre&] Sea_War_Theatre object copied by the current object.
*/
Sea_War_Theatre::Sea_War_Theatre(const Sea_War_Theatre& Template) : War_Theatre(Template){

};

/**
 * @brief The constructor of the Sea_War_Theatre class. 
 * It takes 3 paramaters, call its base class constructor and pass the paramaters to initialise the name of the war_theatre and assigns the two sides of the war.
 * @param name [string] name of the war_theatre.
 * @param sideA [CountryGroup*] CountryGroup side A in the war.
 * @param sideB [CountryGroup*] CountryGroup side B in the war.
*/
Sea_War_Theatre::Sea_War_Theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/) : War_Theatre(name/*, SideA, SideB*/){

};

/**
 * @brief Destructor of the Sea_War_Theatre class.
*/
Sea_War_Theatre::~Sea_War_Theatre() {

};

/**
 * @brief clone funtion, to clone the current Sea_War_Theatre object and returns it.
 * @return A new Sea_War_Theatre which copying the current object.
*/
War_Theatre* Sea_War_Theatre::cloneTheatre() {
    return new Sea_War_Theatre(*this);
};