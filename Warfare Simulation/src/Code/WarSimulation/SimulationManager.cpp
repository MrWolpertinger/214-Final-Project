#include <iostream>
#include <string>
#include <algorithm>
#include "HeaderFiles/SimulationManager.h"

SimulationManager::SimulationManager() {
    cout<<"\033[1m\033[32m"<<"COS214 PROJECT - RUNTIME TERRORS - WAR SIMULATOR"<<"\033[0m"<<endl;

    string startNewSimulation;
    cout<<"Do you want to start a new simulation(Y/N)?"<<endl;
    cin>>startNewSimulation;
    transform(startNewSimulation.begin(), startNewSimulation.end(), startNewSimulation.begin(), ::tolower);
    if (startNewSimulation.compare("y")==0){
		
        string simulationType;
        WarSimulation* newSimulation;

        string simulationName;
        cout<<"What is the name of this simulation?"<<endl;
        cin.ignore();
        getline(cin, simulationName);

        cout<<"Do you want the simulation to be in real mode or design mode(R/D)?"<<endl;
        cin>>simulationType;
        transform(simulationType.begin(), simulationType.end(), simulationType.begin(), ::tolower);
        if (simulationType.compare("r")==0){
            newSimulation = new RealModeWarSimulation();
        }else{
            newSimulation = new DesignModeWarSimulation();
        }

        newSimulation->setName(simulationName);

        delete newSimulation;

	}else{
        cout<<"GOODBYE"<<endl;
	}
}

SimulationManager::~SimulationManager() {
    
}

void SimulationManager::addWarSimulation(WarSimulation* ws){
    table.insert(pair<string, WarSimulation*>(ws->getID(), ws));
}

void SimulationManager::removeWarSimulation(string id){
    table.erase(id);
}

WarSimulation* SimulationManager::getWarSimulation(string id){
    return table.find(id)->second;
}

void SimulationManager::showAllWarSimulations(){
    map<string, WarSimulation*>::iterator itr;
    for (itr = table.begin(); itr != table.end(); ++itr){
        cout<<itr->first<<itr->second->getName()<<endl;
    }
}