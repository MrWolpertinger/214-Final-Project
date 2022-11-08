#ifndef REALMODEWARSIMULATION_H
#define REALMODEWARSIMULATION_H

#include "WarSimulation.h"
#include<string>
//#include "File.h"
using namespace std;

class RealModeWarSimulation : public WarSimulation{
public:
	RealModeWarSimulation();
    ~RealModeWarSimulation();
	void setUp();
	void run();
	void warloop();
	void check(int,int);
};

#endif