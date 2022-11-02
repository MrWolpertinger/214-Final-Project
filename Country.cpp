#include "Country.h"
#include "CountryStrategy.h"
#include "CountryStrategy.cpp"
#include "WarPhase.h"
#include "WarPhase.cpp"
#include<iostream>
using namespace std;
/*
Country::Country(string name) : AlliedForce(name) {
    cout << name << " has been successfully created. \n";
}

void Country::print(){
    cout << "============================CountryInfo============================\n";
    cout << "Country Name: " << this.name << "\n";
    cout << "Country Leader: " << this.leader << "\n";

    bool o = false;
    if (this.isNeutral)
        o = true;
    cout << "Country Neutral: " << o << "\n";

    bool surr = false;
    if (this.flag)
        surr = true;
    cout << "Country Surrendered: " << surr;

    cout << "Country Military Expenditure: " << this.totalMilitarySpending << "\n";
    cout << "Unlisted Citizens: " << this.unlistedCitizens << "\n";
    cout << "Deployed Citizens: " << this.deployedCitizens << "\n";
    cout << "Fighting Citizens: " << this.fightingCitizens << "\n";
    cout << "Stationed Citizens: " << this.stationedCitizens << "\n";
    cout << "Returned Citizens: " << this.returnedCitizens << "\n";
    cout << "Death Count: " << this.deathtoll << "\n";
    cout << "===================================================================\n";
}

void Country::increaseRandSpending(long amount){
    this.totalMilitarySpending = amount;
}*/
/*
void Country::setAlliance(AlliedForce* a){
    if (this.A  == NULL){
        this.A = a;
        cout << "This country now belongs to " << a.getName();
        return;
    }
    else{
        this.A.remove(this); 
        this.A = a;
        cout << "This country now belongs to " << a.getName();
        return;
    }
}

void Country::receiveDamage(int amount){
    if (this.HP - amount <= 0)
        this.HP = 0;
    else
        this.HP -= amount;
    cout << this.name << " has taken " << amount << " damage and their HP is now " << this.HP << ".\n";
}

void Country::attack(AlliedForce* c){
    int x = this.arsenal->getDamage();
    cout << this.getName() << " is now attacking " << c.getName() << ".\n";
    c.receiveDamage(x);
}
*/
void Country::setWarPhase(){
    char answer ;
    cout<<"What Phase of the war is the Country in currently ? \n Type 'A' - IntelligencePhase \n Type 'B' - InitiationPhase \n Type 'C' - OccupationPhase \n Type 'D' - FinishedPhase \n Type 'E' - NeutralPhase \n" ;
    cin>> answer ;
    switch(answer){
      case 'A':
        this->phase = new IntelligencePhase() ;
        cout<<"IntelligencePhase chosen \n";
        break;
      case 'B':
        this->phase = new InitiationPhase();
        cout<<"InitiationPhase chosen \n";
        break;
      case 'C':
        this->phase = new OccupationPhase();
        cout<<"OccupationPhase chosen \n";
        break;
      case 'D':
        this->phase = new FinishedPhase();
        cout<<"FinishedPhase chosen \n";
        break;
      case 'E':
        this->phase = new NeutralPhase();
        cout<<"NeutralPhase chosen \n";
        break;
      default:
        cout<<"No strategy chosen \n" ;
      
    }
  // delete phase ;
   //phase = phase_ ;
}

void Country::iteratePhases(WarPhase* phase_){
    delete phase;
    this->phase = phase_ ;
}

string Country::getCurrentPhase(){
    
   return phase->getPhase();
}


void Country::changeWarPhase(){
    phase->change(this) ;
}

void Country::setCountryStrategy(){
    char answer ;
    cout<<"What Strategy is the Country using currently ? \n Type 'A' if country is Aggresive \n Type 'B' if country is Defensive \n Type 'C' if country is Supportive ." << endl ;
    cin>> answer ;
    switch (answer){
     case 'A':
        this->strategy = new Aggresive() ;
        cout<<"Aggrasive Strategy chosen \n" ;
        break;
     case 'B':
        this->strategy = new Defensive() ;
        cout<<"Defensive Strategy chosen \n" ;
        break;
    case 'C':
        this->strategy = new Supportive() ;
        cout<<"Supportive Strategy chosen \n" ;
        break;
    default:
       cout<<"No strategy chosen \n" ;
    }
    
}

string Country::getStrategy(){
    cout<< strategy->getCountryStrategy() << endl ;
    return strategy->getCountryStrategy();
}


/*

void Country::requestAssistance(AlliedForce* c){
    CountryGroupIterator* ptr = c->CreateGroupIterator();
    string tmp = "";

    for (ptr; ptr->hasNext(); ptr->next()){
        tmp = (*ptr)->getState();
        if (tmp == "supportive"){
            //do something
            cout << this.getName() << " is now receiving assistance from " << (*ptr)->getName() << ".\n";
            return;
        }
    }
    cout << "No countries in this alliance are in supportive mode.\n";
}
*/
// void Country::attack(TransportationCorridor TC){
// }

int main(){
    Country c ;
    c.setCountryStrategy();
    c.setWarPhase();
    c.getStrategy();
    c.getCurrentPhase();
}