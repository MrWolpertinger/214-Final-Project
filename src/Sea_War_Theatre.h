#ifndef SEA_WAR_THEATRE_H
#define SEA_WAR_THEATRE_H

#include "War_Theatre.h"

class Sea_War_Theatre : public War_Theatre
{
private:
    Sea_War_Theatre(const Sea_War_Theatre& Template);
    Sea_War_Theatre() {};
public:
    const int TT = 3;
    Sea_War_Theatre(std::string name, Country* SideA, Country* SideB);
    ~Sea_War_Theatre();
    War_Theatre* cloneTheatre();//
    std::string getDescription();//
    int getType() {return 3;};
};

#endif