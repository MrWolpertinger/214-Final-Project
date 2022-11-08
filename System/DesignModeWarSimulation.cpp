#include <iostream>
#include <string>
#include <algorithm>
#include "DesignModeWarSimulation.h"
#include "Battle.h"
#include "War_Theatre.h"
#include "Land_War_Theatre.h"
#include "Sea_War_Theatre.h"
#include "Airspace_War_Theatre.h"
#include "TransportationCorridor.h"
#include "ConfigClass.h"

#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

DesignModeWarSimulation::DesignModeWarSimulation()
{
	this->setUp();
}

DesignModeWarSimulation::~DesignModeWarSimulation()
{
}

void DesignModeWarSimulation::setUp()
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

	string colors[3] = {BLUE, CYAN, GREEN};

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
	countryGroups = new CountryGroup *[noOfCountryGroups];

	for (int cg = 1; cg <= noOfCountryGroups; cg++)
	{
		cout << "\n\n\n\nCountry Group ";
		if (cg != 3)
		{
			cout << "(Non-neutral Country Group) " << cg << ":" << endl;
			// newCountryGroup->setIsNeutral(false);
		}
		else
		{
			cout << "(Neutral Country Group) " << cg << ":" << endl;
		}

		cout << "Country Group Name: ";
		cin.ignore();
		getline(cin, countryGroupNameInput);
		CountryGroup *newCountryGroup = new CountryGroup(countryGroupNameInput);
		countryGroups[cg - 1] = newCountryGroup;

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
			cout << colors[(i - 1) % 3];
			cout << "\n\nCountry " << i << ":" << endl;

			cout << "Country Name: ";
			cin.ignore();
			getline(cin, countryNameInput);
			Country *newCountry = new Country(countryNameInput);
			newCountry->setCountryStrategy('A');

			cout << "Country Leader: ";
			// cin.ignore();
			getline(cin, countryLeaderInput);
			newCountry->setLeader(countryLeaderInput);

			cout << "Total Military Spending: ";
			// cin.ignore();
			// getline(cin, totalMilitarySpendingInput);
			cin >> totalMilitarySpendingInput;
			totalMilitarySpending = stol(totalMilitarySpendingInput);
			newCountry->stats->setBudget(totalMilitarySpending);
			// newCountry->setTotalMilitarySpending(totalMilitarySpendingInput);

			// newCountry.setIsNeutral(cg==3?true:false);
			// newCountry.setFlag(false);
			// newCountry.setDeathToll(0);

			cout << "Unlisted Citizens: ";
			cin >> unlistedCitizens;
			newCountry->stats->setUnlisted(stoi(unlistedCitizens));

			// cout << "Refugee Count: ";
			// cin.ignore();
			// getline(cin, refugeeCount);
			// // newCountry.setRefugeeCount(stoi(refugeeCount));

			cout << "Enlisted Citizens: ";
			cin >> enlistedCitizens;
			newCountry->stats->setEnlisted(stoi(enlistedCitizens));

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

			cout << "Vehicles:" << endl;

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

			TransportationCorridor *countryTransportationCorridor = new TransportationCorridor(stoi(carCount), stoi(busCount), stoi(truckCount), stoi(cargoTrainCount), stoi(cargoShipCount));

			newCountry->setTransportationCorridor(countryTransportationCorridor);

			// newCountry->setRefugeeCount(0);
			// newCountry->setDeployedCitizens(0);
			// newCountry->fightingCitizens(0);
			// newCountry->setStationedCitizens(0);
			// newCountry->setReturnedCitizens(0);
			// newCountry->setDeathtoll(0);

			newCountry->stats->setRefugee(0);
			newCountry->stats->setDeployed(0);
			newCountry->stats->setFighting(0);
			newCountry->stats->setStationed(0);
			newCountry->stats->setReturned(0);
			newCountry->stats->setDeath(0);

			// newCountry->refugeeCount=0;
			// newCountry->deployedCitizens=0;
			// newCountry->fightingCitizens=0;
			// newCountry->stationedCitizens=0;
			// newCountry->returnedCitizens=0;
			// newCountry->deathtoll=0;

			// countryGroups[cg-1]->Allies.push_back(newCountry);//fix

			countryGroups[cg - 1]->add(newCountry);
		}
		cout << RESET;
	}

	ConfigClass *c = ConfigClass::instance();
	c->ParseConfigFile("../Data/config.toml");

	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < c->ListOfCountries[i].NumberOfWeapons; j++)
	// 	{
	// 		std::cout << c->ListOfCountries[i].countryForces[j].MaxTroops << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	int countryNo=0;
	for (int cg = 1; cg <= noOfCountryGroups; cg++){
		for (int i = 1; i <= countryGroups[cg-1]->Allies.size(); i++){
			//(Country*)(countryGroups[cg-1]->Allies.at(i-1))->produceWeapons((Country*)(countryGroups[cg-1]->Allies.at(i-1))->stats->getBudget());
			c->ListOfCountries[countryNo].NoOfWeapons;
			countryNo++;
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

void DesignModeWarSimulation::interrupt()
{
	string continueInput;
	string tweakSimulation;
	cout << "The simulation has been paused." << endl;
	cout << "Do you want to tweak the simulation(Y/N)?" << endl;
	cin >> tweakSimulation;
	transform(tweakSimulation.begin(), tweakSimulation.end(), tweakSimulation.begin(), ::tolower);
	if (tweakSimulation == "y")
	{
		tweak();
	}
	cout << "Press Enter when you want to continue the simulation." << endl;
	cin >> continueInput;
	continueSimulation();
}

void DesignModeWarSimulation::tweak()
{
	ConfigClass *myConfig = ConfigClass::instance();
	string multiplierChoice;
	string newMultiplierValue;
	cout << "You can change the following multipliers: Army, Weapons, Support" << endl;
	cout << "Which multiplier would you like to change(A/W/S):? " << endl;
	cin >> multiplierChoice;
	cout << "What is the new multiplier value (out of 100)? " << endl;
	cin >> newMultiplierValue;
	transform(multiplierChoice.begin(), multiplierChoice.end(), multiplierChoice.begin(), ::tolower);
	if (multiplierChoice == "a")
	{
		// myConfig->ChangableX[0] = stoi(newMultiplierValue);
		armyMULTIPLIER = stoi(newMultiplierValue);
	}
	else if (multiplierChoice == "w")
	{
		// myConfig->ChangableX[1] = stoi(newMultiplierValue);
		weaponsMULTIPLIER = stoi(newMultiplierValue);
	}
	else if (multiplierChoice == "s")
	{
		// myConfig->ChangableX[2] = stoi(newMultiplierValue);
		supportMULTIPLIER = stoi(newMultiplierValue);
	}
}

void DesignModeWarSimulation::continueSimulation()
{
	cout << "The simulation is running again." << endl;
}

void DesignModeWarSimulation::run()
{
	cout << "The war has begun." << endl;
	cout << "If you want to pause the simulation press p." << endl;
	warIsActive = true;
	warloop();
}

void DesignModeWarSimulation::warloop()
{
	cout << "\033[31m"
		 << "Warphase: Occupation"
		 << "\033[0m" << endl;
	if (isThereANeutralCountryGroup == "y")
	{
		int neutralJoinsWar = rand() % countryGroups[2]->Allies.size();
		if (isThereANeutralCountryGroup == "y" && neutralJoinsWar == 0)
		{
			countryGroups[0]->add(countryGroups[2]->Allies.at(0));
		}
	}

	string countryAStrategy, countryBStrategy;

	int time = 50;

	while (warIsActive)
	{

		time += rand() % 10;
		Country *countryA = (Country *)countryGroups[0]->Allies.at(rand() % countryGroups[0]->Allies.size());
		Country *countryB = (Country *)countryGroups[1]->Allies.at(rand() % countryGroups[0]->Allies.size());

		string countryChoiceA;
		string countryChoiceB;
		cout << "What would you like to do"
			 << " for country " << countryA->getName() << ": \nAttack (A) \nRequest Assistance (R) \nChange Strategy (S) (A/R/S)";
		cin >> countryChoiceA;
		transform(countryChoiceA.begin(), countryChoiceA.end(), countryChoiceA.begin(), ::tolower);
		if (countryChoiceA == "a")
		{
			string warTheatreName;
			cout << "War Theatre Name: ";
			cin.ignore();
			getline(cin, warTheatreName);

			War_Theatre *newWarTheatre = new Land_War_Theatre(warTheatreName, countryA, countryB);

			Battle *newBattle = new Battle("Battle of " + warTheatreName, to_string(time), to_string(time + rand() % 5), countryA, countryB, 'L');
			countryA->print();
			countryB->print();
			countryA->attack(countryB);
		}
		else if (countryChoiceA == "r")
		{
			countryA->requestAssistance();
		}
		else if (countryChoiceA == "s")
		{
			cout << "What is the strategy for " << countryA->getName() << "(A/D/S)" << endl;
			cin >> countryAStrategy;
			transform(countryAStrategy.begin(), countryAStrategy.end(), countryAStrategy.begin(), ::toupper);
			countryA->setCountryStrategy(countryAStrategy.at(0));
		}
		else if (countryChoiceA == "d")
		{
		}
		else if (countryChoiceA == "p")
		{
			interrupt();
		}

		cout << "What would you like to do"
			 << "for country" << countryB->getName() << ": \nAttack (A) \nRequest Assistance (R) \n Change Strategy (S) (A/R/S)";
		cin >> countryChoiceB;
		transform(countryChoiceB.begin(), countryChoiceB.end(), countryChoiceB.begin(), ::tolower);
		if (countryChoiceB == "a")
		{
			string warTheatreName;
			cout << " Name: ";
			cin.ignore();
			getline(cin, warTheatreName);
			War_Theatre *newWarTheatre = new Land_War_Theatre(warTheatreName, countryB, countryA);

			Battle *newBattle = new Battle("Battle of " + warTheatreName, to_string(time), to_string(time + rand() % 5), countryB, countryA, 'L');

			countryA->attack(countryB);
		}
		else if (countryChoiceB == "r")
		{
			// countryA->requestAssistance(countryGroups[0]->Allies.at(rand()%countryGroups[0]->Allies.size()));
			countryB->requestAssistance();
		}
		else if (countryChoiceB == "s")
		{
			cout << "What is the strategy for " << countryB->getName() << "(A/D/S)" << endl;
			cin >> countryBStrategy;
			transform(countryBStrategy.begin(), countryBStrategy.end(), countryBStrategy.begin(), ::toupper);
			countryA->setCountryStrategy(countryBStrategy.at(0));
		}
		else if (countryChoiceA == "d")
		{
		}
		else if (countryChoiceB == "p")
		{
			interrupt();
		}
	}
}