#include<iostream>
#include "ConfigClass.h"
using namespace std;

int main(){
    ConfigClass::ParseConfigFile("config.toml");
    //ConfigClass::ListOfCountries;
    for(int i = 0; i < ConfigClass::SizeOfArr; i++) {
        for(int j = 0; j < ConfigClass::ListOfCountries[i].NumOfForces; j++) {
            std::cout << ConfigClass::ListOfCountries[i].countryForces[j].MaxTroops << " ";
        }
        std::cout << "\n";
    }
	return 0;
}