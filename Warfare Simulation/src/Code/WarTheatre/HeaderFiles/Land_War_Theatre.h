#ifndef LAND_WAR_THEATRE_H
#define LAND_WAR_THEATRE_H
#include "War_Theatre.h"

class Land_War_Theatre : public War_Theatre
{
private:
    Land_War_Theatre(const Land_War_Theatre& Template);
public:
    Land_War_Theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/);
    ~Land_War_Theatre();
    War_Theatre* cloneTheatre();
};

#endif