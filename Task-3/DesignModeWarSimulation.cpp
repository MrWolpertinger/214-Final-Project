#include <iostream>
#include <string>
#include <algorithm>
#include "DesignModeWarSimulation.h"

DesignModeWarSimulation::DesignModeWarSimulation() {
	this->setUp();
}

DesignModeWarSimulation::~DesignModeWarSimulation() {
	
}

void DesignModeWarSimulation::interrupt(){
    string continueInput;
    string tweakSimulation;
    cout<<"The simulation has been paused."<<endl;
    cout<<"Do you want to tweak the simulation(Y/N)?"<<endl;
    cin>>tweakSimulation;
    transform(tweakSimulation.begin(), tweakSimulation.end(), tweakSimulation.begin(), ::tolower);
    if (tweakSimulation=="y"){
        tweak();
    }
    cout<<"Press Enter when you want to continue the simulation."<<endl;
    cin>>continueInput;
    continueSimulation();
}

void DesignModeWarSimulation::tweak(){
    string multiplierChoice;
    string newMultiplierValue;
    cout<<"You can change the following multipliers: Army, Weapons, Support"<<endl;
    cout<<"Which multiplier would you like to change(A/W/S):? "<<endl;
    cin>>multiplierChoice;
    cout<<"What is the new multiplier value? "<<endl;
    cin>>newMultiplierValue;
    transform(multiplierChoice.begin(), multiplierChoice.end(), multiplierChoice.begin(), ::tolower);
    if (multiplierChoice=="a"){

    }else if(multiplierChoice=="w"){

    }else if(multiplierChoice=="s"){

    }
    
    


}

void DesignModeWarSimulation::continueSimulation(){
    cout<<"The simulation is running again."<<endl;
}

void DesignModeWarSimulation::run()
{
	cout << "The war has begun." << endl;
	cout << "If you want to pause the simulation press p." << endl;
	warIsActive = true;
	warloop();
}

void DesignModeWarSimulation::warloop(){
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