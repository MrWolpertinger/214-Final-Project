 #include <iostream>
 #include "HeaderFile/SimulationManager.h"
 #include "HeaderFile/WarSimulation.h"
 #include "HeaderFile/RealModeWarSimulation.h"
 #include "HeaderFile/DesignModeWarSimulation.h"


 using namespace std;


 int main() {
    SimulationManager* ourSimulator = new SimulationManager();

    delete ourSimulator;
    
    return 0;
 }
