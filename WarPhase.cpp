#include "WarPhase.h"
//#include "Country.h"
#include<iostream>
using namespace std ;

void IntelligencePhase::change(Country* c){
    c->setWarPhase(new InitiationPhase);
}

string IntelligencePhase::getPhase(){
    return "Intelligence Phase ." ;
}

void InitiationPhase::change(Country* c){
   c->setWarPhase(new OccupationPhase);
}

string InitiationPhase::getPhase(){
    return "Initiation Phase ." ;
}

void OccupationPhase::change(Country* c){
    c->setWarPhase(new FinishedPhase);
}

string OccupationPhase::getPhase(){
    return "Occupation Phase ." ;
}

void FinishedPhase::change(Country* c){
    c->setWarPhase(new NeutralPhase);
}

string FinishedPhase::getPhase(){
    return "Finished Phase ." ;
}

void NeutralPhase::change(Country* c){
   c->setWarPhase(new InitiationPhase);
}

string NeutralPhase::getPhase(){
    return "Neutral Phase ." ;
}








