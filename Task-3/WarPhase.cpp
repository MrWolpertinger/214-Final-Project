#include "WarPhase.h"
//#include "Country.h"
#include<iostream>
using namespace std ;

void IntelligencePhase::change(Country* c){
    c->setWarPhase(new InitiationPhase);
}

string IntelligencePhase::getPhase(){
    cout<<"Intelligence Phase .\n" ;
    return "Intelligence Phase ." ;
}

void InitiationPhase::change(Country* c){
   c->setWarPhase(new OccupationPhase);
}

string InitiationPhase::getPhase(){
    cout<<"Initiation Phase .\n" ;
    return "Initiation Phase ." ;
}

void OccupationPhase::change(Country* c){
    c->setWarPhase(new FinishedPhase);
}

string OccupationPhase::getPhase(){
    cout<<"Occupation Phase .\n" ;
    return "Occupation Phase ." ;
}

void FinishedPhase::change(Country* c){
    c->setWarPhase(new NeutralPhase);
}

string FinishedPhase::getPhase(){
    cout<<"Finished Phase .\n" ;
    return "Finished Phase ." ;
}

void NeutralPhase::change(Country* c){
   c->setWarPhase(new InitiationPhase);
}

string NeutralPhase::getPhase(){
    cout<<"Neutral Phase .\n" ;
    return "Neutral Phase ." ;
}








