#include "HeaderFiles/WarPhase.h"
//#include "Country.h"
#include<iostream>

using namespace std ;

/**
 * @brief Changes the phase of the war from the IntelligencePhase to the InitiationPhase.
 * @param c [country] object involved in the war
*/
void IntelligencePhase::change(Country* c){
    c->iteratePhases(new InitiationPhase);
}

/**
 * @brief A getter for the warPhase.
 * @return A message anouncing the phase of the war.
*/
string IntelligencePhase::getPhase(){
    cout<<"Intelligence Phase .\n" ;
    return "Intelligence Phase ." ;
}

/**
 * @brief Changes the phase of the war from the InitiationPhase to the OccupationPhase.
 * @param c [country] object involved in the war
*/
void InitiationPhase::change(Country* c){
   c->iteratePhases(new OccupationPhase);
}

/**
 * @brief A getter for the warPhase.
 * @return A message anouncing the phase of the war.
*/
string InitiationPhase::getPhase(){
    cout<<"Initiation Phase .\n" ;
    return "Initiation Phase ." ;
}

/**
 * @brief Changes the phase of the war from the OccupationPhase to the FinishedPhase.
 * @param c [country] object involved in the war
*/
void OccupationPhase::change(Country* c){
    c->iteratePhases(new FinishedPhase);
}

/**
 * @brief A getter for the warPhase.
 * @return A message anouncing the phase of the war.
*/
string OccupationPhase::getPhase(){

    cout<<"\033[31m"<<"Occupation Phase ."<<"\033[0m"<<endl ;
    return "Occupation Phase ." ;
}

/**
 * @brief Changes the phase of the war from the FinishedPhase to the NeutralPhase.
 * @param c [country] object involved in the war
*/
void FinishedPhase::change(Country* c){
    c->iteratePhases(new NeutralPhase);
}

/**
 * @brief A getter for the warPhase.
 * @return A message anouncing the phase of the war.
*/
string FinishedPhase::getPhase(){
    cout<<"Finished Phase .\n" ;
    return "Finished Phase ." ;
}

/**
 * @brief Changes the phase of the war from the NeutralPhase to the InitiationPhase.
 * @param c [country] object involved in the war
*/
void NeutralPhase::change(Country* c){
   c->iteratePhases(new InitiationPhase);
}

/**
 * @brief A getter for the warPhase.
 * @return A message anouncing the phase of the war.
*/
string NeutralPhase::getPhase(){
    cout<<"Neutral Phase .\n" ;
    return "Neutral Phase ." ;
}








