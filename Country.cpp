#include "Country.h"
#include "CountryStrategy.h"
#include "CountryStrategy.cpp"
#include "WarPhase.h"
#include "WarPhase.cpp"
#include "Weapons.h"
#include "Weapons.cpp"
#include "Military.cpp"
#include "AlliedForce.h"
#include "AlliedForce.cpp"
//#include "Military.cpp"
#include "CountryGroupIterator.h"

#include<iostream>
using namespace std;

Country::Country(string name) : AlliedForce(name) {
    this->setCG(false);
    cout << name << " has been successfully created. \n";
}

Country::~Country(){
    cout << "Country destroyed" << endl ;
}

void Country::print(){
    cout << "============================CountryInfo============================\n";
    cout << "Country Name: " << this->getName()<< "\n";
    cout << "Country Leader: " << this->leader << "\n";

    bool o = false;
    if (this->isNeutral)
        o = true;
    cout << "Country Neutral: " << o << "\n";

    bool surr = false;
    if (this->flag)
        surr = true;
    cout << "Country Surrendered: " << surr;

    cout << "Country Military Expenditure: " << this->totalMilitarySpending << "\n";
    cout << "Unlisted Citizens: " << this->unlistedCitizens << "\n";
    cout << "Deployed Citizens: " << this->deployedCitizens << "\n";
    cout << "Fighting Citizens: " << this->fightingCitizens << "\n";
    cout << "Stationed Citizens: " << this->stationedCitizens << "\n";
    cout << "Returned Citizens: " << this->returnedCitizens << "\n";
    cout << "Death Count: " << this->deathtoll << "\n";
    cout << "===================================================================\n";
}

void Country::setAlliance(AlliedForce* a){
    if (this->A  == NULL){
        this->A = a;
        cout << "This country now belongs to " << a->getName();
        return;
    }
    else{
        (this->A)->remove(this); 
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
    cout << this->getName()<< " has taken " << amount << " damage and their HP is now " << this->HP << ".\n";
}

/**
 * @brief
 * This attack function takes an opposing AlliedForce object as a parameter. The country calling the function then calculates it's damage and calls the receiving countries receiveDamage function with the appropriate damage variable. 
 *
 * @param c The opposing country which is being attacked.
 */
void Country::attack(Country* c){
    string phase1 = "";
    phase1 = c->getCurrentPhase();
    if (phase1 == "Intelligence Phase ."){
        cout << "Cannot attack in the intelligence phase!\n";
        return;
    }
    else if (phase1 == "Finished Phase ."){
        cout << "Cannot attack whilst the war is finished!\n";
        return;
    }

    string check = this->getStrategy();
    if (check != "Aggrasive Strategy"){
        cout << this->getName() << " is not in the aggressive state and cannot attack!\n";
        return;
    }

    int x = this->arsenal->getDamage();
    //ArmyItorator* p = (this->_mil)->createItorator();
    //int x = x + static_cast<int>((this->_mil)->getCatagoryDamage());
    cout << this->getName() << " is now attacking " << c->getName() << ".\n";
    c->receiveDamage(x);
}


//getState
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
 * @param c 
 *////Take note 
 
void Country::requestAssistance(Country* c){
    //CountryGroupIterator* ptr = c->CreateGroupIterator(this->Countries);
    //string tmp = "";

    //for (ptr; ptr->hasNext(); ptr->next()){
        //AlliedForce* p = (*ptr);
        if ((c->getStrategy() == "Supportive Strategy") && (c->getHp() > 0)){
            c->support(this);
            cout << this->getName() << " is now receiving assistance from " << c->getName() << ".\n";
            return;
        }
   // }
    cout << "No countries in this alliance are in supportive mode.\n";
}
/*
void Country::requestAssistance(){
    CountryGroupIterator* ptr = c->CreateGroupIterator();
    string tmp = "";

    for (ptr; ptr->hasNext(); ptr->next()){
        AlliedForce* p = (*ptr);
        if ((p->getState() == "supportive") && (p->getHp() > 0)){
            c->support(this);
            cout << this->getName() << " is now receiving assistance from " << (*ptr)->getName() << ".\n";
            return;
        }
    }
    cout << "No countries in this alliance are in supportive mode.\n";
}
*/
















// void Country::attack(TransportationCorridor TC){
//     int dmg = ((this->arsenal->getDamage())*0.2)/5;
//     TC.takeDamage(dmg);
// }

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

int Country::getRefugee(){
    return this->refugeeCount;
}

int Country::getUnlisted(){
    return this->unlistedCitizens;
}

int Country::getEnlisted(){
    return this->enlistedCitizens;
}

int Country::getDeployed(){
    return this->deployedCitizens;
}

int Country::getFighting(){
    return this->deployedCitizens;
}

int Country::getStationed(){
    return this->stationedCitizens;
}

int Country::getReturned(){
    return this->returnedCitizens;
}

int Country::getDeath(){
    return this->deathtoll;
}

int Country::getHp(){
    return this->HP;
}

long Country::getBudget(){
    return this->totalMilitarySpending;
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

void Country::setRefugee(int x){
    this->refugeeCount = x;
}

void Country::setUnlisted(int x){
    this->unlistedCitizens = x;
}

void Country::setEnlisted(int x){
    this->enlistedCitizens = x;
}

void Country::setDeployed(int x){
    this->deployedCitizens = x;
}

void Country::setFighting(int x){
    this->fightingCitizens = x;
}

void Country::setStationed(int x){
    this->stationedCitizens = x;
}

void Country::setReturned(int x){
    this->returnedCitizens = x;
}

void Country::setDeath(int x){
    this->deathtoll = x;
}

void Country::setBudget(long x){
    this->totalMilitarySpending = x;
}

void Country::setMil(Military* m){
    this->_mil = m;
}

int main(){
    Country* c = new Country("za");
    Country* a = new Country("bb");
    a->setWarPhase();
    a->setCountryStrategy();
    c->attack(a);
    c->requestAssistance(a) ;

}