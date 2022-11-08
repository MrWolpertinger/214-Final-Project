#include "Airspace_War_Theatre.h"

/**
 * @brief The copy constructor of the Airspace_War_Theatre class. Copy the attribute of another objects.
 * @param Template [Airspace_War_Theatre&] Airspace_War_Theatre object copied by the current object.
*/
Airspace_war_theatre::Airspace_war_theatre(const Airspace_war_theatre& Template) : War_Theatre(Template){};

/**
 * @brief The constructor of the Airspace_War_Theatre class. 
 * It takes 3 paramaters, call its base class constructor and pass the paramaters to initialise the name of the war_theatre and assigns the two sides of the war.
 * @param name [string] name of the war_theatre.
 * @param sideA [CountryGroup*] CountryGroup side A in the war.
 * @param sideB [CountryGroup*] CountryGroup side B in the war.
*/
Airspace_war_theatre::Airspace_war_theatre(std::string name, AlliedForce* SideA, AlliedForce* SideB) : War_Theatre(name, SideA, SideB){};

/**
 * @brief Destructor of the Airspace_War_Theatre class.
*/
Airspace_war_theatre::~Airspace_war_theatre() {};

/**
 * @brief clone funtion, to clone the current Airspace_war_theatre object and returns it.
 * @return A new Airspace_war_theatre which copying the current object.
*/
War_Theatre* Airspace_war_theatre::cloneTheatre() {
    return new Airspace_war_theatre(*this);
};

/**
 * @brief get the description of the theatre.
 * @return A string variable describing the theatre.
*/
std::string Airspace_war_theatre::getDescription() {
    return "The sky";
};