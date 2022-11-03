#include <iostream>
#include <string>
#include <algorithm>
#include "DesignModeWarSimulation.h"
//#include "ConfigClass.h"

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
	// countryGroups = new CountryGroup*[noOfCountryGroups];

	for (int cg = 1; cg <= noOfCountryGroups; cg++)
	{
		cout << "\n\n\n\nCountry Group ";
		if (cg != 3)
		{
			cout << "(Non-neutral Country Group) " << cg << ":" << endl;
		}
		else
		{
			cout << "(Neutral Country Group) " << cg << ":" << endl;
		}

		cout << "Country Group Name: ";
		cin.ignore();
		getline(cin, countryGroupNameInput);
		// CountryGroup* newCountryGroup = new CountryGroup(countryGroupNameInput);

		// cout << "Is this country group neutral(Y/N)?" << endl;
		// cin >> isNeutralInput;
		// transform(isNeutralInput.begin(), isNeutralInput.end(), isNeutralInput.begin(), ::tolower);
		// // newCountryGroup->setIsNeutral(isNeutralInput=="y"?true:false);

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
			// Country* newCountry = new Country(countryNameInput);

			cout << "Country Leader: ";
			cin.ignore();
			getline(cin, countryLeaderInput);
			// newCountry.setLeader(countryLeaderInput);

			cout << "Total Military Spending: ";
			// cin.ignore();
			// getline(cin, totalMilitarySpendingInput);
			cin >> totalMilitarySpendingInput;
			totalMilitarySpending = stol(totalMilitarySpendingInput);
			// newCountry.setTotalMilitarySpending(totalMilitarySpendingInput);

			// newCountry.setIsNeutral(cg==3?true:false);
			// newCountry.setFlag(false);
			// newCountry.setDeathToll(0);

			cout << "Unlisted Citizens: ";
			cin >> unlistedCitizens;
			// newCountry.setUnlistedCitizens(stoi(unlistedCitizens));

			// cout << "Refugee Count: ";
			// cin.ignore();
			// getline(cin, refugeeCount);
			// // newCountry.setRefugeeCount(stoi(refugeeCount));

			cout << "Enlisted Citizens: ";
			cin >> enlistedCitizens;
			// newCountry.setEnlistedCitizens(stoi(enlistedCitizens));

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

			// newCountry.setRefugeeCount(0);
			// newCountry.setDeployedCitizens(0);
			// newCountry.fightingCitizens(0);
			// newCountry.setStationedCitizens(0);
			// newCountry.setReturnedCitizens(0);
			// newCountry.setDeathtoll(0);

			// countryGroups[cg-1]->Allies.push_back(newCountry);
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
		//ChangableX[0] = stoi(newMultiplierValue);
	}
	else if (multiplierChoice == "w")
	{
		//ChangableX[1] = stoi(newMultiplierValue);
	}
	else if (multiplierChoice == "s")
	{
		//ChangableX[2] = stoi(newMultiplierValue);
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
	// int neutralJoinsWar= rand()%countryGroups[2]->Allies.size;
	// if (isThereANeutralCountryGroup=="y" && neutralJoinsWar==0){
	//     countryGroups[0].addMember(countryGroups[2]->Allies.at(0));
	// }

	// string countryAStrategy, countryBStrategy;

	// Battle* newBattle = new Battle();
	// WarTheatre* newWarTheatre = new LandWarTheatre();
	// // while (warIsActive){
	// //Country countryA* = countryGroups[0]->Allies.at(rand()%countryGroups[0]->Allies.size());
	// //Country countryB* = countryGroups[1]->Allies.at(rand()%countryGroups[0]->Allies.size());
	// if (countryAStrategy=="a"){
	//     countryA->attack(countryB);
	// }else{
	//     countryB->attack(countryA);
	// }

	string countryChoiceA;
	string countryChoiceB;
	//cout << "What would you like to do"<<"for country"<<countryA->getName()<<": \nAttack (A) \nRequest Assistance (R) \n Change Strategy (S) (A/R/S)";
	cin >> countryChoiceA;
	transform(countryChoiceA.begin(), countryChoiceA.end(), countryChoiceA.begin(), ::tolower);
	if (countryChoiceA == "a")
	{
		//countryA->attack(countryB);
	}
	else if (countryChoiceA == "r"){
		//countryA->requestAssistance(countryGroups[0]->Allies.at(rand()%countryGroups[0]->Allies.size()));
	}else if (countryChoiceA == "s"){
		// cout<<"What is the strategy for "<<countryA->getName()<<"(A/D/S)"<<endl;
		// cin>>countryAStrategy;
		// cout<<"What is the strategy for "<<countryB->getName()<<"(A/D/S)"<<endl;
		// cin>>countryBStrategy;
		// transform(countryAStrategy.begin(), countryAStrategy.end(), countryAStrategy.begin(), ::tolower);
		// transform(countryBStrategy.begin(), countryBStrategy.end(), countryBStrategy.begin(), ::tolower);
	}else if(countryChoiceA == "d"){
		
	}else if(countryChoiceA == "p"){
		interrupt();
	}

	//cout << "What would you like to do"<<"for country"<<countryB->getName()<<": \nAttack (A) \nRequest Assistance (R) \n Change Strategy (S) (A/R/S)";
	cin >> countryChoiceB;
	transform(countryChoiceB.begin(), countryChoiceB.end(), countryChoiceB.begin(), ::tolower);
	if (countryChoiceB == "a")
	{
		//countryB->attack(countryA);
	}
	else if (countryChoiceB == "r"){
		//countryA->requestAssistance(countryGroups[0]->Allies.at(rand()%countryGroups[0]->Allies.size()));
	}else if (countryChoiceB == "s"){
		// cout<<"What is the strategy for "<<countryA->getName()<<"(A/D/S)"<<endl;
		// cin>>countryAStrategy;
		// cout<<"What is the strategy for "<<countryB->getName()<<"(A/D/S)"<<endl;
		// cin>>countryBStrategy;
		// transform(countryAStrategy.begin(), countryAStrategy.end(), countryAStrategy.begin(), ::tolower);
		// transform(countryBStrategy.begin(), countryBStrategy.end(), countryBStrategy.begin(), ::tolower);
	}else if(countryChoiceA == "d"){
		
	}else if(countryChoiceB == "p"){
		interrupt();
	}
	// }
}