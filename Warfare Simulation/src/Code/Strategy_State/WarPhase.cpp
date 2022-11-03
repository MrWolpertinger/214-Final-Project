#include "HeaderFiles/WarPhase.h"
//#include "Country.h"
#include<iostream>

using namespace std ;

void IntelligencePhase::change(Country* c){
    c->iteratePhases(new InitiationPhase);
}

string IntelligencePhase::getPhase(){
    cout<<"Intelligence Phase .\n" ;
    return "Intelligence Phase ." ;
}

void InitiationPhase::change(Country* c){
   c->iteratePhases(new OccupationPhase);
}

string InitiationPhase::getPhase(){
    cout<<"Initiation Phase .\n" ;
    return "Initiation Phase ." ;
}

void OccupationPhase::change(Country* c){
    c->iteratePhases(new FinishedPhase);
}

string OccupationPhase::getPhase(){

    cout<<"\033[31m"<<"Occupation Phase ."<<"\033[0m"<<endl ;
    return "Occupation Phase ." ;
}

void FinishedPhase::change(Country* c){
    c->iteratePhases(new NeutralPhase);
}

string FinishedPhase::getPhase(){
    cout<<"Finished Phase .\n" ;
    return "Finished Phase ." ;
}

void NeutralPhase::change(Country* c){
   c->iteratePhases(new InitiationPhase);
}

string NeutralPhase::getPhase(){
    cout<<"Neutral Phase .\n" ;
    return "Neutral Phase ." ;
}








