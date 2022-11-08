#ifndef WAR_THEATRE_H
#define WAR_THEATRE_H
#include <string>
#include "Country.h"

class War_Theatre {
protected:
    std::string _name = "";
    AlliedForce* _SideA = nullptr;
    AlliedForce* _SideB = nullptr;
    std::string _area = "";
    War_Theatre(const War_Theatre& Template);
    War_Theatre() {};
public:
    int TT;
    War_Theatre(std::string n, AlliedForce* SideA, AlliedForce* SideB);
    ~War_Theatre() {};

    virtual War_Theatre* cloneTheatre()=0;

    std::string getName();
    void setName(std::string name);

    std::string getArea();
    void setArea(std::string area);

    virtual AlliedForce* getSideA();
    virtual AlliedForce* getSideB();
    void setSideA(AlliedForce* sideA);
    void setSideB(AlliedForce* sideB);
    virtual std::string getDescription()=0;
    virtual int getType() {return 0;};
};

#endif