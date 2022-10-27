#include "WarSimulation.h"

WarSimulation::WarSimulation() {
	
}

WarSimulation::~WarSimulation() {
	
}

void WarSimulation::setUp() {
	bool isNeutral;
	int noOfCountryGroups;
	int noOfCountries;
	string isNeutralInput;
	string noOfCountryGroupsInput;
	string noOfCountriesInput;
	string countryNameInput;


	//Number of country Groups
    cout<<"How many country groups are there in this simulation?"<<endl;
    cin>>noOfCountryGroupsInput;
	noOfCountryGroups = stoi(noOfCountryGroupsInput);


    
    for (int i = 1;i<=noOfCountryGroups;i++){
		cout<<"Country Group "<<i<<":"<<endl;


		cout<<"Is this country group neutral(Y/N)?"<<endl;
		cin>>isNeutralInput;
		transform(isNeutralInput.begin(), isNeutralInput.end(), isNeutralInput.begin(), ::tolower);



		//Number of countries
		cout<<"How many countries are there in this country group?"<<endl;
		cin>>noOfCountriesInput;
		noOfCountries=stoi(noOfCountriesInput);



		for (int i=1; i<=noOfCountries; i++){
			cout<<"Country "<<i<<":"<<endl;

			cout<<"Country Name:?"<<endl;
			cin.ignore();
        	getline(cin, countryNameInput);
			transform(countryNameInput.begin(), countryNameInput.end(), countryNameInput.begin(), ::tolower);
		}




	}
}

WarSimulation* WarSimulation::clone() {

}

void WarSimulation::displayInformation() {

}

void WarSimulation::run() {

}

string WarSimulation::getID(){
	return id;
}

void WarSimulation::setName(string n){
	name = n;
}

string WarSimulation::getName(){
	return name;
}