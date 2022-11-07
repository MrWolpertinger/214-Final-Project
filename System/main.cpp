 #include <iostream>
 #include "SimulationManager.h"
 #include "WarSimulation.h"
 #include "RealModeWarSimulation.h"
 #include "DesignModeWarSimulation.h"
 //#include "ConfigClass.h"


 using namespace std;


 int main() {

   // ConfigClass* c = ConfigClass::instance();
   //  c->ParseConfigFile("../Data/config.toml");
    
   //  for(int i = 0; i < c->SizeOfArr; i++) {
   //      for(int j = 0; j < c->ListOfCountries[i].NumOfForces; j++) {
   //          std::cout << c->ListOfCountries[i].countryForces[j].MaxTroops << " ";
   //      }
   //      std::cout << "\n";
   //  }

    SimulationManager* ourSimulator = new SimulationManager();

    delete ourSimulator;
    
    return 0;
 }
