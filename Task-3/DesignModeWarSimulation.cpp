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