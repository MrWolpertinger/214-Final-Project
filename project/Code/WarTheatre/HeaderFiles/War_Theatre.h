#ifndef WAR_THEATRE_H
#define WAR_THEATRE_H
#include <string>
#include "AlliedForce/HeaderFiles/Country.h"

class War_Theatre {
protected:
    std::string _name = "";
    Country* _SideA = nullptr;
    Country* _SideB = nullptr;
    std::string _area = "";
    War_Theatre(const War_Theatre& Template);
    War_Theatre() {};
public:
    const int TT = 0;
    War_Theatre(std::string n, Country* SideA, Country* SideB);
    ~War_Theatre() {};

    virtual War_Theatre* cloneTheatre();

    std::string getName();
    void setName(std::string name);

    std::string getArea();
    void setArea(std::string area);

    Country* getSideA();
    Country* getSideB();
    void setSideA(Country* sideA);
    void setSideB(Country* sideB);
    virtual std::string getDescription() {};
};

#endif