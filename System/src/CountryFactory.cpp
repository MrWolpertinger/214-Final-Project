#include "CountryFactory.h"

/**
*@brief Create a new country class.
*@param name [string] name of the country.
*@return new Country* object.
*/
Country* CountryFactory::createCountry(string name,string leader,int budget) {
	return new Country(name,leader,budget);
}
 
