#ifndef LAND_WAR_THEATRE_H
#define LAND_WAR_THEATRE_H
#include "War_Theatre.h"

class Land_War_Theatre : public War_Theatre
{
private:
    Land_War_Theatre(const Land_War_Theatre& Template);
    Land_War_Theatre() {};
public:
    const int TT = 2;
    Land_War_Theatre(std::string name, Country* SideA, Country* SideB);
    ~Land_War_Theatre();
    War_Theatre* cloneTheatre();//
    std::string getDescription();//
    int getType() {return 2;};
};

#endif