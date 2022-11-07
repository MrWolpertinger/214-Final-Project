#include <iostream>
#include <string>
#include <algorithm>
#include "RealModeWarSimulation.h"
#include "Battle.h"
#include "War_Theatre.h"
#include "Land_War_Theatre.h"
#include "Sea_War_Theatre.h"
#include "Airspace_War_Theatre.h"
#include "TransportationCorridor.h"

RealModeWarSimulation::RealModeWarSimulation() {
	this->setUp();
}

RealModeWarSimulation::~RealModeWarSimulation() {
	
}

void RealModeWarSimulation::setUp()
{
	bool isNeutral;
	int noOfCountryGroups;
	int noOfCountries;
	long totalMilitarySpending;
	string unlistedCitizens;
	string refugeeCount;
	string enlistedCitizens;
	string deployedCitizens;
	string fightingCitizens;
	string stationedCitizens;
	string returnedCitizens;
	string deathtoll;
	// string isNeutralInput;
	string countryGroupNameInput;
	// string noOfCountryGroupsInput;
	string noOfCountriesInput;
	string countryNameInput;
	string countryLeaderInput;
	string totalMilitarySpendingInput;

	cout << "\033[31m"
		 << "Warphase: Intelligence"
		 << "\033[0m" << endl;

	// // Number of country Groups
	// cout << "How many country groups are there in this simulation?" << endl;
	// cin >> noOfCountryGroupsInput;
	// noOfCountryGroups = stoi(noOfCountryGroupsInput);
	// // countryGroups = new CountryGroup*[noOfCountryGroups];

	cout << "Is there a neutral country group in this simulation?(Y/N)" << endl;
	cin >> isThereANeutralCountryGroup;
	transform(isThereANeutralCountryGroup.begin(), isThereANeutralCountryGroup.end(), isThereANeutralCountryGroup.begin(), ::tolower);
	if (isThereANeutralCountryGroup == "y")
	{
		noOfCountryGroups = 3;
	}
	else
	{
		noOfCountryGroups = 2;
	}
	countryGroups = new CountryGroup*[noOfCountryGroups];

	for (int cg = 1; cg <= noOfCountryGroups; cg++)
	{
		cout << "\n\n\n\nCountry Group ";
		if (cg != 3)
		{
			cout << "(Non-neutral Country Group) " << cg << ":" << endl;
			//newCountryGroup->setIsNeutral(false);
		}
		else
		{
			cout << "(Neutral Country Group) " << cg << ":" << endl;
		}

		cout << "Country Group Name: ";
		cin.ignore();
		getline(cin, countryGroupNameInput);
		CountryGroup* newCountryGroup = new CountryGroup(countryGroupNameInput);

		if (cg != 3)
		{
			newCountryGroup->setIsNeutral(false);
		}
		else
		{
			newCountryGroup->setIsNeutral(true);
		}

		// cout << "Is this country group neutral(Y/N)?" << endl;
		// cin >> isNeutralInput;
		// transform(isNeutralInput.begin(), isNeutralInput.end(), isNeutralInput.begin(), ::tolower);

		// Number of countries
		cout << "How many countries are there in this country group?" << endl;
		cin >> noOfCountriesInput;
		noOfCountries = stoi(noOfCountriesInput);

		for (int i = 1; i <= noOfCountries; i++)
		{

			cout << "\n\nCountry " << i << ":" << endl;

			cout << "Country Name: ";
			cin.ignore();
			getline(cin, countryNameInput);
			Country* newCountry = new Country(countryNameInput);

			cout << "Country Leader: ";
			cin.ignore();
			getline(cin, countryLeaderInput);
			newCountry->setLeader(countryLeaderInput);

			cout << "Total Military Spending: ";
			// cin.ignore();
			// getline(cin, totalMilitarySpendingInput);
			cin >> totalMilitarySpendingInput;
			totalMilitarySpending = stol(totalMilitarySpendingInput);
			//newCountry->setTotalMilitarySpending(totalMilitarySpendingInput);

			// newCountry.setIsNeutral(cg==3?true:false);
			// newCountry.setFlag(false);
			// newCountry.setDeathToll(0);

			cout << "Unlisted Citizens: ";
			cin >> unlistedCitizens;
			newCountry->unlistedCitizens=stoi(unlistedCitizens);

			// cout << "Refugee Count: ";
			// cin.ignore();
			// getline(cin, refugeeCount);
			// // newCountry.setRefugeeCount(stoi(refugeeCount));

			cout << "Enlisted Citizens: ";
			cin >> enlistedCitizens;
			newCountry->enlistedCitizens=stoi(enlistedCitizens);

			// cout << "Deployed Citizens: ";
			// cin.ignore();
			// getline(cin, deployedCitizens);
			// // newCountry.setDeployedCitizens(stoi(deployedCitizens));

			// cout << "Fighting Citizens: ";
			// cin.ignore();
			// getline(cin, fightingCitizens);
			// // newCountry.setFightingCitizens(stoi(fightingCitizens));

			// cout << "Stationed Citizens: ";
			// cin.ignore();
			// getline(cin, stationedCitizens);
			// // newCountry.setStationedCitizens(stoi(stationedCitizens));

			// cout << "Returned Citizens: ";
			// cin.ignore();
			// getline(cin, returnedCitizens);
			// // newCountry.setReturnedCitizens(stoi(returnedCitizens));

			// cout << "Deathtoll: ";
			// cin.ignore();
			// getline(cin, deathtoll);
			// // newCountry.setDeathtoll(stoi(deathtoll));

			cout<<"Vehicles:"<<endl;

			string carCount;
			cout << "How many cars does this country have: ";
			cin >> carCount;

			string busCount;
			cout << "How many buses does this country have: ";
			cin >> busCount;

			string truckCount;
			cout << "How many trucks does this country have: ";
			cin >> truckCount;

			string cargoTrainCount;
			cout << "How many cargo trains does this country have: ";
			cin >> cargoTrainCount;

			string cargoShipCount;
			cout << "How many cargo ships does this country have: ";
			cin >> cargoShipCount;

			TransportationCorridor* countryTransportationCorridor = new TransportationCorridor(stoi(carCount), stoi(busCount), stoi(truckCount), stoi(cargoTrainCount), stoi(cargoShipCount));
			
			newCountry->setTransportationCorridor(countryTransportationCorridor);

			// newCountry->setRefugeeCount(0);
			// newCountry->setDeployedCitizens(0);
			// newCountry->fightingCitizens(0);
			// newCountry->setStationedCitizens(0);
			// newCountry->setReturnedCitizens(0);
			// newCountry->setDeathtoll(0);

			newCountry->refugeeCount=0;
			newCountry->deployedCitizens=0;
			newCountry->fightingCitizens=0;
			newCountry->stationedCitizens=0;
			newCountry->returnedCitizens=0;
			newCountry->deathtoll=0;

			//countryGroups[cg-1]->Allies.push_back(newCountry);//fix
			countryGroups[cg-1]->add(newCountry);
		}
	}

	cout << "\033[31m"
		 << "Warphase: Initiation"
		 << "\033[0m" << endl;
	this->run();
	cout << "\033[31m"
		 << "Warphase: Finished"
		 << "\033[0m" << endl;
}

void RealModeWarSimulation::run()
{
	cout << "The war has begun." << endl;
	warIsActive = true;
	warloop();
}

void RealModeWarSimulation::warloop(){
	cout << "\033[31m"
		 << "Warphase: Occupation"
		 << "\033[0m" << endl;
	int neutralJoinsWar= rand()%countryGroups[2]->Allies.size();
	if (isThereANeutralCountryGroup=="y" && neutralJoinsWar==0){
	   countryGroups[0]->add(countryGroups[2]->Allies.at(0));
	}

	string countryAStrategy, countryBStrategy;

	int time = 50;


	while (warIsActive){

	time+=rand()%10;
	Country* countryA = (Country*)countryGroups[0]->Allies.at(rand()%countryGroups[0]->Allies.size());
	Country* countryB = (Country*)countryGroups[1]->Allies.at(rand()%countryGroups[0]->Allies.size());
	

	string countryChoiceA;
	string countryChoiceB;
	cout << "What would you like to do"<<"for country"<<countryA->getName()<<": \nAttack (A) \nRequest Assistance (R) \n Change Strategy (S) (A/R/S)";
	cin >> countryChoiceA;
	transform(countryChoiceA.begin(), countryChoiceA.end(), countryChoiceA.begin(), ::tolower);
	if (countryChoiceA == "a")
	{
		string warTheatreName;
		cout << " Name: ";
		cin.ignore();
		getline(cin, warTheatreName);
		War_Theatre* newWarTheatre = new Land_War_Theatre(warTheatreName,countryA,countryB);

		Battle* newBattle = new Battle("Battle of "+warTheatreName, to_string(time), to_string(time+rand()%5),countryA,countryB,'L');

		countryA->attack(countryB);
	}
	else if (countryChoiceA == "r"){
		countryA->requestAssistance();
	}else if (countryChoiceA == "s"){
		countryA->setCountryStrategy();
	}else if(countryChoiceA == "d"){
		
	}

	cout << "What would you like to do"<<"for country"<<countryB->getName()<<": \nAttack (A) \nRequest Assistance (R) \n Change Strategy (S) (A/R/S)";
	cin >> countryChoiceB;
	transform(countryChoiceB.begin(), countryChoiceB.end(), countryChoiceB.begin(), ::tolower);
	if (countryChoiceB == "a")
	{
		 string warTheatreName;
		cout << " Name: ";
		cin.ignore();
		getline(cin, warTheatreName);
		War_Theatre* newWarTheatre = new Land_War_Theatre(warTheatreName,countryB,countryA);

		Battle* newBattle = new Battle("Battle of "+warTheatreName, to_string(time), to_string(time+rand()%5),countryB,countryA,'L');

		countryA->attack(countryB);
	}
	else if (countryChoiceB == "r"){
		//countryA->requestAssistance(countryGroups[0]->Allies.at(rand()%countryGroups[0]->Allies.size()));
		countryB->requestAssistance();
	}else if (countryChoiceB == "s"){
		countryB->setCountryStrategy();
	}else if(countryChoiceA == "d"){
		
	}
	}
}