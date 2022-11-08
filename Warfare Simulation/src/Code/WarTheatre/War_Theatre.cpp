#include "HeaderFiles/War_Theatre.h"
/**
 * @brief The constructor of the War_Theatre class. 
 * It takes 3 paramaters to initialise the name of the war_theatre and assigns the two sides of the war.
 * @param name [string] name of the war_theatre.
 * @param sideA [CountryGroup*] CountryGroup side A in the war.
 * @param sideB [CountryGroup*] CountryGroup side B in the war.
*/
War_Theatre::War_Theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/) {
    _name = name;
    /*_SideA = SideA;
    _SideB = SideB;*/
};

/**
 * @brief The copy constructor of the War_Theatre class. Copy the attribute of another objects.
 * @param Template [War_Theatre&] War_Theatre object copied by the current object.
*/
War_Theatre::War_Theatre(const War_Theatre& Template) {
    _name = Template._name;
    /*_SideA = Template._SideA;
    _SideB = Template._SideB*/
};

/**
 * @brief clone funtion, to clone the current object and return it.
 * @return returns a new war_Theatre which copying the current object.
*/
War_Theatre* War_Theatre::cloneTheatre() {
    return new War_Theatre(*this);
};

/**
 * @brief Getter for the name of the current Theatre.
 * @return Name of the current war_Theatre.
*/
std::string War_Theatre::getName() {
    return _name;
};

/**
 * @brief Getter for the CountryGroup A.
 * @return A countryGroup object for side A.
*/
/*CountryGroup* War_Theatre::getSideA() {
    return _SideA;
};*/

/**
 * @brief Getter for the CountryGroup B.
 * @return A countryGroup object for side B.
*/
/*CountryGroup* War_Theatre::getSideB() {
    return _SideB;
};*/