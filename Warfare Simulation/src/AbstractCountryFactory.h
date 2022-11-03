#ifndef __AbstractCountryFactory_h__
#define __AbstractCountryFactory_h__

#include "Country.h"

using namespace std;

class AbstractCountryFactory
{
	public: 
		virtual Country* createCountry(string name) = 0;
};

#endif
