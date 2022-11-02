#ifndef REALMODEWARSIMULATION_H
#define REALMODEWARSIMULATION_H

#include "WarSimulation.h"
#include<string>
//#include "File.h"
using namespace std;

class RealModeWarSimulation : public WarSimulation{


private:
	string id;

public:
	RealModeWarSimulation();
    ~RealModeWarSimulation();
	void run();
	void warloop();
};

#endif