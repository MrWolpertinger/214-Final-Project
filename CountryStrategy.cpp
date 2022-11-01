#include "CountryStrategy.h"
#include<iostream>

using namespace std ;

//CountryStrategy::~CountryStrategy(){}
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
    cout<<"The Country Strategy is Aggrasive" ;
    return "Aggrasive Strategy";
}

string Defensive::getCountryStrategy(){
    cout<<"The Country Strategy is Defensive" ;
    return "Defensive Strategy";
}

string Supportive::getCountryStrategy(){
    cout<<"The Country Strategy is Supportive" ;
    return "Supportive Strategy";
}

void Defensive::Defend(Country* c){
    cout<<"Defending the country!" ;
    c->increaseRandSpending(10);

}

void Aggresive::Attack(Country* c){
   cout<<"Attacking now!" ;
   c->receiveDamage(10) ;
}

