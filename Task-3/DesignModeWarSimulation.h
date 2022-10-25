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
    void interrupt();
    void tweak();
    void continueSimulation();
};

#endif