#ifndef Airspace_war_theatre_H
#define Airspace_war_theatre_H
#include "War_Theatre.h"

class Airspace_war_theatre : public War_Theatre
{
private:
    Airspace_war_theatre(const Airspace_war_theatre& Template);
    Airspace_war_theatre() {};
public:
    const int TT = 1;
    Airspace_war_theatre(std::string name, Country* SideA, Country* SideB);
    ~Airspace_war_theatre();
    War_Theatre* cloneTheatre();//
    virtual std::string getDescription();//
};

#endif