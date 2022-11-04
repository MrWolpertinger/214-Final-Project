#ifndef __CountryFactory_h__
#define __CountryFactory_h__

#include "Country.h"
#include "AbstractCountryFactory.h"


class CountryFactory: public AbstractCountryFactory
{

	public: virtual Country* createCountry(string name);
};

#endif
