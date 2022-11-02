#include <iostream>
#include <string>
#include <algorithm>
#include "RealModeWarSimulation.h"

RealModeWarSimulation::RealModeWarSimulation() {
	this->setUp();
}

RealModeWarSimulation::~RealModeWarSimulation() {
	
}

void RealModeWarSimulation::run()
{
	cout << "The war has begun." << endl;
	cout << "If you want to pause the simulation press p." << endl;
	warIsActive = true;
	warloop();
}

void RealModeWarSimulation::warloop(){
	cout <<"\033[31m"<< "Warphase: Occupation" <<"\033[0m"<<endl;
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
    // cout<<"What is the strategy for "<<countryA->getName()<<"(A/D/S)"<<endl;
    // cin>>countryAStrategy;
    // cout<<"What is the strategy for "<<countryB->getName()<<"(A/D/S)"<<endl;
    // cin>>countryBStrategy;
    // transform(countryAStrategy.begin(), countryAStrategy.end(), countryAStrategy.begin(), ::tolower);
    // transform(countryBStrategy.begin(), countryBStrategy.end(), countryBStrategy.begin(), ::tolower);
    // if (countryAStrategy=="a"){
    //     countryA->attack(countryB);
    // }else{
    //     countryB->attack(countryA);
    // }
	// }
}