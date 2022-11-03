#include "CountryFactory.h"

/**
*@brief 
*@param name [string] name of the country
*@returns Country
*/
Country* CountryFactory::createCountry(string name) {
	return new Country(name);
}
 
