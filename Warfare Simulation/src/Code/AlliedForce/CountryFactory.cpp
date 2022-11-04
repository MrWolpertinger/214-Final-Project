#include "HeaderFiles/CountryFactory.h"

/**
*@brief Create a new country class.
*@param name [string] name of the country.
*@return new Country* object.
*/
Country* CountryFactory::createCountry(string name) {
	return new Country(name);
}
 
