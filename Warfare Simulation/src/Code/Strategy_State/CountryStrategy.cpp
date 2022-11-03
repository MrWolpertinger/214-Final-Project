#include "HeaderFiles/CountryStrategy.h"
#include<iostream>

using namespace std ;

CountryStrategy::~CountryStrategy(){}
Aggresive::~Aggresive(){
    cout<<"Deconstructing Aggresive Strategy\n " ;
}

Defensive::~Defensive(){
    cout<<"Deconstructing Defensive Strategy\n " ;
}
Supportive::~Supportive(){
    cout<<"Deconstructing Supportive Strategy\n " ;
}

string Aggresive::getCountryStrategy(){
   
    return "Aggrasive Strategy";
}

string Defensive::getCountryStrategy(){
    
    return "Defensive Strategy";
}

string Supportive::getCountryStrategy(){
    
    return "Supportive Strategy";
}
