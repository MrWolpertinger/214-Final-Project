#include "WarPhase.h"

/**
 * @brief Change the state of the country from the Intelligence Phase to the subsequent using the warPhase iterator.
 * @param c The country involved in the war.
*/
void IntelligencePhase::change(Country* c){
    c->iteratePhases(new InitiationPhase);
}

/**
 * @brief A getter for the phase of the war.
 * @return A string variable indicating the phase of the war.
*/
string IntelligencePhase::getPhase(){
    cout<<"Intelligence Phase .\n";
    return "Intelligence Phase .";
}

/**
 * @brief Change the state of the country from the Initiation Phase to the subsequent using the warPhase iterator.
 * @param c The country involved in the war.
*/
void InitiationPhase::change(Country* c){
   c->iteratePhases(new OccupationPhase);
}

/**
 * @brief A getter for the phase of the war.
 * @return A string variable indicating the phase of the war.
*/
string InitiationPhase::getPhase(){
    cout<<"Initiation Phase .\n" ;
    return "Initiation Phase ." ;
}

/**
 * @brief Change the state of the country from the Occupation Phase to the subsequent using the warPhase iterator.
 * @param c The country involved in the war.
*/
void OccupationPhase::change(Country* c){
    c->iteratePhases(new FinishedPhase);
}

/**
 * @brief A getter for the phase of the war.
 * @return A string variable indicating the phase of the war.
*/
string OccupationPhase::getPhase(){

    cout<<"\033[31m"<<"Occupation Phase ."<<"\033[0m"<<endl ;
    return "Occupation Phase ." ;
}

/**
 * @brief Change the state of the country from the Finished Phase to the subsequent using the warPhase iterator.
 * @param c The country involved in the war.
*/
void FinishedPhase::change(Country* c){
    c->iteratePhases(new NeutralPhase);
}

/**
 * @brief A getter for the phase of the war.
 * @return A string variable indicating the phase of the war.
*/
string FinishedPhase::getPhase(){
    cout<<"Finished Phase .\n" ;
    return "Finished Phase ." ;
}

/**
 * @brief Change the state of the country from the Neutral Phase to the subsequent using the warPhase iterator.
 * @param c The country involved in the war.
*/
void NeutralPhase::change(Country* c){
   c->iteratePhases(new InitiationPhase);
}

/**
 * @brief A getter for the phase of the war.
 * @return A string variable indicating the phase of the war.
*/
string NeutralPhase::getPhase(){
    cout<<"Neutral Phase .\n" ;
    return "Neutral Phase ." ;
}








