 #include <iostream>
 #include "SimulationManager.h"
 #include "WarSimulation.h"
 #include "RealModeWarSimulation.h"
 #include "DesignModeWarSimulation.h"


 using namespace std;


 int main() {
    SimulationManager* ourSimulator = new SimulationManager();

    delete ourSimulator;
    
    return 0;
 }
