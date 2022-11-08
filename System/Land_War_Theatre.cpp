#include "Land_War_Theatre.h"

/**
 * @brief The copy constructor of the Land_War_Theatre class. Copy the attribute of another objects.
 * @param Template [Land_War_Theatre&] Land_War_Theatre object copied by the current object.
*/
Land_War_Theatre::Land_War_Theatre(const Land_War_Theatre& Template) : War_Theatre(Template){};

/**
 * @brief The constructor of the Land_War_Theatre class. 
 * It takes 3 paramaters, call its base class constructor and pass the paramaters to initialise the name of the war_theatre and assigns the two sides of the war.
 * @param name [string] name of the war_theatre.
 * @param sideA [CountryGroup*] CountryGroup side A in the war.
 * @param sideB [CountryGroup*] CountryGroup side B in the war.
*/
Land_War_Theatre::Land_War_Theatre(std::string name, AlliedForce* SideA, AlliedForce* SideB) : War_Theatre(name, SideA, SideB){};

/**
 * @brief Destructor of the Land_War_Theatre class.
*
Land_War_Theatre::~Land_War_Theatre() {};

/**
 * @brief clone funtion, to clone the current Land_War_Theatre object and returns it.
 * @return A new Land_War_Theatre which copying the current object.
*/
War_Theatre* Land_War_Theatre::cloneTheatre() {
    return new Land_War_Theatre(*this);
};

/**
 * @brief get the description of the theatre.
 * @return A string variable describing the theatre.
*/
std::string Land_War_Theatre::getDescription() {
    return "The terrain";
};