#ifndef SEA_WAR_THEATRE_H
#define SEA_WAR_THEATRE_H

#include "War_Theatre.h"

class Sea_War_Theatre : public War_Theatre
{
private:
    Sea_War_Theatre(const Sea_War_Theatre& Template);
public:
    Sea_War_Theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/);
    ~Sea_War_Theatre();
    War_Theatre* cloneTheatre();
};

#endif