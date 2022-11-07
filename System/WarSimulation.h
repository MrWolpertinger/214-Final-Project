#ifndef WARSIMULATION_H
#define WARSIMULATION_H

//#include "File.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include "CountryGroup.h"

using namespace std;

class WarSimulation {


private:
	string id;
    string name;

public:
    CountryGroup** countryGroups;
    bool warIsActive;
    string isThereANeutralCountryGroup;

	WarSimulation();
    ~WarSimulation();
    virtual void setUp();
    WarSimulation* clone();
    void displayInformation();
    virtual void run();
    string getID();
    void setName(string);
    string getName();
    virtual void warloop();
    //void setCountryGroups();
};

#endif