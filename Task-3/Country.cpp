#include "Country.h"

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
}

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

string Country::getState(){
    return this.strategy;
}

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

// void Country::attack(TransportationCorridor TC){
// }