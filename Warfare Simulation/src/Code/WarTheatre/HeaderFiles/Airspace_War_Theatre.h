#ifndef Airspace_war_theatre_H
#define Airspace_war_theatre_H
#include "War_Theatre.h"

class Airspace_war_theatre : public War_Theatre
{
private:
    Airspace_war_theatre(const Airspace_war_theatre& Template);
public:
    Airspace_war_theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/);
    ~Airspace_war_theatre();
    War_Theatre* cloneTheatre();
};

#endif