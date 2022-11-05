#include "Country.h"
#include "WarPhase.h"

#include<iostream>
using namespace std;

Country::Country(string name) : AlliedForce(name) {
    this->setCG(false);
    cout << name << " has been successfully created. \n";
}

void Country::print(){
    cout << "============================CountryInfo============================\n";
    cout << "Country Name: " << this->getName() << "\n";
    cout << "Country Leader: " << this->getLeader() << "\n";

    bool o = false;
    if (this->isNeutral)
        o = true;
    cout << "Country Neutral: " << o << "\n";

    bool surr = false;
    if (this->flag)
        surr = true;
    cout << "Country Surrendered: " << surr;
    stats->print();
}

void Country::setAlliance(AlliedForce* a){
    if (this->A  == NULL){
        this->A = a;
        cout << "This country now belongs to " << a->getName();
        return;
    }
}

void Country::receiveDamage(int amount){
    if (this->HP - amount <= 0)
        this->HP = 0;
    else
        this->HP -= amount;
    cout << this->getName() << " has taken " << amount << " damage and their HP is now " << this->HP << ".\n";
    transportationCorridor->receiveDamage(amount*0.2);
}

/**
 * @brief
 * This attack function takes an opposing AlliedForce object as a parameter. The country calling the function then calculates it's damage and calls the receiving countries receiveDamage function with the appropriate damage variable. 
 *
 * @param c The opposing country which is being attacked.
 */
void Country::attack(AlliedForce* c){
    string phase = "";
    phase = this->phase->getPhase();
    if (phase == "Intelligence Phase ."){
        cout << "Cannot attack in the intelligence phase!\n";
        return;
    }
    else if (phase == "Finished Phase ."){
        cout << "Cannot attack whilst the war is finished!\n";
        return;
    }

    string check = this->getStrategy();
    if (check != "Aggressive Strategy"){
        cout << this->getName() << " is not in the aggressive state and cannot attack!\n";
        return;
    }

    int x = arsenal->getDamage();
    ArmyItorator* p = (this->_mil)->createIterator();
    x += static_cast<int>(_mil->getMilitaryDamage());
    cout << this->getName() << " is now attacking " << c->getName() << ".\n";
    ((Country*)c)->receiveDamage(x);
}

string Country::getStrategy(){
    cout<< strategy->getCountryStrategy() << endl ;
    return strategy->getCountryStrategy();
}

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

/**
 * @brief This function creates an iterator for the calling Country's CountryGroup, and iterates through this group. If any of the AlliedForces in this group are in the supportive strategy, then that country will support the country calling for assistance.
 * 
 * 
 */
void Country::requestAssistance(){
    CountryGroupIterator* ptr = myGroup->CreateGroupIterator();
    string tmp = "";

    for (ptr->first(); ptr->hasNext(); ptr->next()){
        Country* c=(Country*)ptr->current();
        if (c->getStrategy() == "supportive" && c->getHp() > 0){
            c->support(this);
            cout << this->getName() << " is now receiving assistance from " << c->getName() << ".\n";
            return;
        }
    }
    cout << "No countries in this alliance are in supportive mode.\n";
}

void Country::support(Country* c){
    this->HP -= 50;
    c->increaseHP(50);
}

void Country::increaseHP(int v){
    this->HP += v;
}

string Country::getLeader(){
    return this->leader;
}

bool Country::getNeutral(){
    return this->isNeutral;
}

bool Country::getsurr(){
    return this->flag;
}

int Country::getHp(){
    return this->HP;
}

void Country::setLeader(string L){
    this->leader = L;
}

void Country::setNeutral(bool b){
    this->isNeutral = b;
}

void Country::setsurr(bool b){
    this->flag = b;
}

void Country::setMil(Military* m){
    this->_mil = m;
}

void Country::setStats(){

}