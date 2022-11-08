#include "War_Theatre.h"


/**
 * @brief The constructor of the War_Theatre class. 
 * It takes 3 paramaters to initialise the name of the war_theatre and assigns the two sides of the war.
 * @param name [string] name of the war_theatre.
 * @param sideA [CountryGroup*] CountryGroup side A in the war.
 * @param sideB [CountryGroup*] CountryGroup side B in the war.
*/
War_Theatre::War_Theatre(std::string name, Country* SideA, Country* SideB) {
    this->_name = name;
    this->_SideA = SideA;
    this->_SideB = SideB;
};

/**
 * @brief The copy constructor of the War_Theatre class. Copy the attribute of another objects.
 * @param Template [War_Theatre&] War_Theatre object copied by the current object.
*/
War_Theatre::War_Theatre(const War_Theatre& Template) {
    this->_name = Template._name;
    this->_SideA = Template._SideA;
    this->_SideB = Template._SideB;
};

/**
 * @brief Getter for the name of the current Theatre.
 * @return Name of the current war_Theatre.
*/
std::string War_Theatre::getName() {
    return this->_name;
};

/**
 * @brief A setter for the name of the Theatre.
 * @param name The name of the warTheatre.
*/
void War_Theatre::setName(std::string name) {
    this->_name = name;
};

/**
 * @brief Getter for the CountryGroup A.
 * @return A countryGroup object for side A.
*/
Country* War_Theatre::getSideA() {
    return this->_SideA;
};

/**
 * @brief Getter for the CountryGroup B.
 * @return A countryGroup object for side B.
*/
Country* War_Theatre::getSideB() {
    return this->_SideB;
};

/**
 * @brief A setter for the country Side A.
 * @param sideA country taking sideA in the war.
*/
void War_Theatre::setSideA(Country* sideA) {
    this->_SideA = sideA;
};

/**
 * @brief A setter for the country Side B.
 * @param sideB country taking sideA in the war.
*/
void War_Theatre::setSideB(Country* sideB) {
    this->_SideB = sideB;
};

/**
 * @brief Getter for the area of the Theatre.
 * @return A countryGroup object for side B.
*/
std::string War_Theatre::getArea() {
    return this->_area;
};

/**
 * @brief A setter for the area of the warTheatre.
 * @param area [in] the area of the war theatre.
*/
void War_Theatre::setArea(std::string area) {
    this->_area = area;
};