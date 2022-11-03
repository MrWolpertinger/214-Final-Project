#ifndef DESIGNMODEWARSIMULATION_H
#define DESIGNMODEWARSIMULATION_H

#include "WarSimulation.h"
#include <string>
//#include "File.h"

using namespace std;

class DesignModeWarSimulation : public WarSimulation{


private:
	string id;

public:
	DesignModeWarSimulation();
    ~DesignModeWarSimulation();
    void setUp();
    void interrupt();
    void tweak();
    void continueSimulation();
    void run();
	void warloop();
};

#endif