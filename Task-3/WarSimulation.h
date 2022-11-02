#ifndef WARSIMULATION_H
#define WARSIMULATION_H

//#include "File.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <string>

using namespace std;

class WarSimulation {


private:
	string id;
    string name;
    string isThereANeutralCountryGroup;
    //CountryGroup** countryGroups;

public:
    bool warIsActive;

	WarSimulation();
    ~WarSimulation();
    void setUp();
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