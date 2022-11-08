#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include <map>
#include <string>
#include "WarSimulation.h"
//#include "File.h"
using namespace std;

class SimulationManager {


private:
	map<string, WarSimulation*> table;

public:
	SimulationManager();
    ~SimulationManager();
    void addWarSimulation(WarSimulation*);
    void removeWarSimulation(string);
    WarSimulation* getWarSimulation(string);
    void showAllWarSimulations();
    
};

#endif