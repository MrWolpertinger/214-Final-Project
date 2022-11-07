#ifndef WAR_THEATRE_H
#define WAR_THEATRE_H
#include <string>
#include "Country.h"

class War_Theatre {
protected:
    std::string _name = "";
    Country* _SideA = nullptr;
    Country* _SideB = nullptr;
    std::string _area = "";
    War_Theatre(const War_Theatre& Template);
    War_Theatre() {};
public:
    int TT;
    War_Theatre(std::string n, Country* SideA, Country* SideB);
    ~War_Theatre() {};

    virtual War_Theatre* cloneTheatre()=0;

    std::string getName();
    void setName(std::string name);

    std::string getArea();
    void setArea(std::string area);

    Country* getSideA();
    Country* getSideB();
    void setSideA(Country* sideA);
    void setSideB(Country* sideB);
    virtual std::string getDescription()=0;
    virtual int getType() {return 0;};
};

#endif