#ifndef WARSIMULATION_H
#define WARSIMULATION_H

//#include "File.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include "Battle.h"
#include "ConfigClass.h"

using namespace std;

class WarSimulation {


protected:
	string id;
    string name;
public:
    CountryGroup** countryGroups;
    bool warIsActive;
    string isThereANeutralCountryGroup;

    int armyMULTIPLIER = 50;
    int weaponsMULTIPLIER = 50;
    int supportMULTIPLIER = 50;

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
};
    //void setCountryGroups();


#endif