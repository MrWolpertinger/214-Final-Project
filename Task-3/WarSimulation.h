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
    bool warIsActive;
    //CountryGroup** countryGroups;

public:
	WarSimulation();
    ~WarSimulation();
    void setUp();
    WarSimulation* clone();
    void displayInformation();
    void run();
    string getID();
    void setName(string);
    string getName();
    void warloop();
};

#endif