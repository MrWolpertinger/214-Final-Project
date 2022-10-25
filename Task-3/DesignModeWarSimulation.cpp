#include <iostream>
#include <string>
#include <algorithm>
#include "DesignModeWarSimulation.h"

DesignModeWarSimulation::DesignModeWarSimulation() {
	bool isNeutral;
	int noOfCountryGroups;
	int noOfCountries;
	string isNeutralInput;
	string noOfCountryGroupsInput;
	string noOfCountriesInput;
	//CountryGroup** CountryGroups = new CountryGroup*[noOfCountryGroups];

    cout<<"How many country groups are there in this simulation?"<<endl;
    cin>>noOfCountryGroupsInput;

	noOfCountryGroups = stoi(noOfCountryGroupsInput);
    
    for (int i = 1;i<=noOfCountryGroups;i++){
		cout<<"Country Group "<<i<<":"<<endl;

		cout<<"Is this country group neutral(Y/N)?"<<endl;
		cin>>isNeutralInput;
		transform(isNeutralInput.begin(), isNeutralInput.end(), isNeutralInput.begin(), ::tolower);

		cout<<"How many countries are there in this country group?"<<endl;
		cin>>noOfCountriesInput;
		transform(noOfCountriesInput.begin(), noOfCountriesInput.end(), noOfCountriesInput.begin(), ::tolower);

	}
}

DesignModeWarSimulation::~DesignModeWarSimulation() {
	
}

void DesignModeWarSimulation::interrupt(){
    string continueInput;
    cout<<"The simulation has been paused."<<endl;
    cout<<"Press Enter when you want to continue the simulation."<<endl;
    cin>>continueInput;
    continueSimulation();
}

void DesignModeWarSimulation::tweak(){

}

void DesignModeWarSimulation::continueSimulation(){
    cout<<"The simulation is running again."<<endl;
}