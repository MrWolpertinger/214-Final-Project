#include<iostream>
#include "ConfigClass.h"
using namespace std;

int main(){
    
    ConfigClass* c = ConfigClass::instance();
    c->ParseConfigFile("config.toml");
    
    for(int i = 0; i < c->SizeOfArr; i++) {
        for(int j = 0; j < c->ListOfCountries[i].NumOfForces; j++) {
            std::cout << c->ListOfCountries[i].countryForces[j].MaxTroops << " ";
        }
        std::cout << "\n";
    }
	return 0;
}