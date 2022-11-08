#include HeaderFile/WarSimulation.h"

WarSimulation::WarSimulation()
{
}

WarSimulation::~WarSimulation()
{
	/*
	for (CountryGroup* cg:countryGroups){
		delete cg;
	}
	delete countryGroups;
	*/
}

void WarSimulation::setUp()
{
	// bool isNeutral;
	// int noOfCountryGroups;
	// int noOfCountries;
	// long totalMilitarySpending;
	// string unlistedCitizens;
	// string refugeeCount;
	// string enlistedCitizens;
	// string deployedCitizens;
	// string fightingCitizens;
	// string stationedCitizens;
	// string returnedCitizens;
	// string deathtoll;
	// //string isNeutralInput;
	// string countryGroupNameInput;
	// //string noOfCountryGroupsInput;
	// string noOfCountriesInput;
	// string countryNameInput;
	// string countryLeaderInput;
	// string totalMilitarySpendingInput;

	// cout <<"\033[31m"<< "Warphase: Intelligence" <<"\033[0m"<<endl;

	// // // Number of country Groups
	// // cout << "How many country groups are there in this simulation?" << endl;
	// // cin >> noOfCountryGroupsInput;
	// // noOfCountryGroups = stoi(noOfCountryGroupsInput);
	// // // countryGroups = new CountryGroup*[noOfCountryGroups];

	// cout << "Is there a neutral country group in this simulation?(Y/N)" << endl;
	// cin >> isThereANeutralCountryGroup;
	// transform(isThereANeutralCountryGroup.begin(), isThereANeutralCountryGroup.end(), isThereANeutralCountryGroup.begin(), ::tolower);
	// if (isThereANeutralCountryGroup=="y"){
	// 	noOfCountryGroups=3;
	// }else{
	// 	noOfCountryGroups=2;
	// }
	// // countryGroups = new CountryGroup*[noOfCountryGroups];


	// for (int cg = 1; cg <= noOfCountryGroups; cg++)
	// {
	// 	cout << "\n\n\n\nCountry Group ";
	// 	if (cg!=3){
	// 		cout<<"(Non-neutral Country Group) " << cg << ":" << endl;
	// 	}else{
	// 		cout<<"(Neutral Country Group) " << cg << ":" << endl;
	// 	}

	// 	cout << "Country Group Name: ";
	// 	cin.ignore();
	// 	getline(cin, countryGroupNameInput);
	// 	// CountryGroup* newCountryGroup = new CountryGroup(countryGroupNameInput);

	// 	// cout << "Is this country group neutral(Y/N)?" << endl;
	// 	// cin >> isNeutralInput;
	// 	// transform(isNeutralInput.begin(), isNeutralInput.end(), isNeutralInput.begin(), ::tolower);
	// 	// // newCountryGroup->setIsNeutral(isNeutralInput=="y"?true:false);

	// 	// Number of countries
	// 	cout << "How many countries are there in this country group?" << endl;
	// 	cin >> noOfCountriesInput;
	// 	noOfCountries = stoi(noOfCountriesInput);

	// 	for (int i = 1; i <= noOfCountries; i++)
	// 	{

	// 		cout << "\n\nCountry " << i << ":" << endl;

	// 		cout << "Country Name: ";
	// 		cin.ignore();
	// 		getline(cin, countryNameInput);
	// 		// Country* newCountry = new Country(countryNameInput);

	// 		cout << "Country Leader: ";
	// 		cin.ignore();
	// 		getline(cin, countryLeaderInput);
	// 		// newCountry.setLeader(countryLeaderInput);

	// 		cout << "Total Military Spending: ";
	// 		//cin.ignore();
	// 		//getline(cin, totalMilitarySpendingInput);
	// 		cin>>totalMilitarySpendingInput;
	// 		totalMilitarySpending = stol(totalMilitarySpendingInput);
	// 		// newCountry.setTotalMilitarySpending(totalMilitarySpendingInput);

	// 		// newCountry.setIsNeutral(cg==3?true:false);
	// 		// newCountry.setFlag(false);
	// 		// newCountry.setDeathToll(0);

	// 		cout << "Unlisted Citizens: ";
	// 		cin >> unlistedCitizens;
	// 		// newCountry.setUnlistedCitizens(stoi(unlistedCitizens));

	// 		// cout << "Refugee Count: ";
	// 		// cin.ignore();
	// 		// getline(cin, refugeeCount);
	// 		// // newCountry.setRefugeeCount(stoi(refugeeCount));

	// 		cout << "Enlisted Citizens: ";
	// 		cin >> enlistedCitizens;
	// 		// newCountry.setEnlistedCitizens(stoi(enlistedCitizens));

	// 		// cout << "Deployed Citizens: ";
	// 		// cin.ignore();
	// 		// getline(cin, deployedCitizens);
	// 		// // newCountry.setDeployedCitizens(stoi(deployedCitizens));

	// 		// cout << "Fighting Citizens: ";
	// 		// cin.ignore();
	// 		// getline(cin, fightingCitizens);
	// 		// // newCountry.setFightingCitizens(stoi(fightingCitizens));

	// 		// cout << "Stationed Citizens: ";
	// 		// cin.ignore();
	// 		// getline(cin, stationedCitizens);
	// 		// // newCountry.setStationedCitizens(stoi(stationedCitizens));

	// 		// cout << "Returned Citizens: ";
	// 		// cin.ignore();
	// 		// getline(cin, returnedCitizens);
	// 		// // newCountry.setReturnedCitizens(stoi(returnedCitizens));

	// 		// cout << "Deathtoll: ";
	// 		// cin.ignore();
	// 		// getline(cin, deathtoll);
	// 		// // newCountry.setDeathtoll(stoi(deathtoll));

	// 		// newCountry.setRefugeeCount(0);
	// 		// newCountry.setDeployedCitizens(0);
	// 		// newCountry.fightingCitizens(0);
	// 		// newCountry.setStationedCitizens(0);
	// 		// newCountry.setReturnedCitizens(0);
	// 		// newCountry.setDeathtoll(0);
			

	// 		// countryGroups[cg-1]->Allies.push_back(newCountry);

	// 	}
	// }

	// cout <<"\033[31m"<< "Warphase: Initiation" <<"\033[0m"<<endl;
	// this->run();
	// cout <<"\033[31m"<< "Warphase: Finished" <<"\033[0m"<<endl;
}

WarSimulation *WarSimulation::clone()
{
	WarSimulation* cloneSimulation = new WarSimulation();
	//cloneSimulation.countryGroups = this.countryGroups;
	return cloneSimulation;
}

void WarSimulation::displayInformation()
{
	cout<<name<<endl;
}

void WarSimulation::run()
{
	// cout << "The war has begun." << endl;
	// cout << "If you want to pause the simulation press p." << endl;
	// warIsActive = true;
	// warloop();
}

string WarSimulation::getID()
{
	return id;
}

void WarSimulation::setName(string n)
{
	name = n;
}

string WarSimulation::getName()
{
	return name;
}

void WarSimulation::warloop(){
	//cout <<"\033[31m"<< "Warphase: Occupation" <<"\033[0m"<<endl;
	// while (warIsActive){
	// 	for (int i = 0;i<10;i++){

	// 	}
	// 	if (countryGroups[0].lost==true){
	// 		warIsActive=false;
	// 		cout << "Country Group"<<countryGroups[0]->getName()<<" has lost the war."<< endl;
	// 	}
	// 	if (countryGroups[1].lost==true){
	// 		warIsActive=false;
	//choose two countries
	//countryGroups[0].receiveDamage()
	// 		cout << "Country Group"<<countryGroups[1]->getName()<<" has lost the war."<< endl;
	// 	}
	// }
}

// void WarSimulation::setCountryGroups(){
// 	thi
// }
