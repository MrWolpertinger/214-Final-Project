#include "CountryGroup.h"

CountryGroup::CountryGroup(string name) : AlliedForce(name) {};

void CountryGroup::setEnemy(CountryGroup* e){
    this->enemy = e;
    cout << this->name << "'s enemy is now " << e->getName() << "\n";
}

string CountryGroup::getName(){
    return this->name;
}

void CountryGroup::print(){
    cout << "============================AllianceInfo============================\n";
    CountryGroupIterator* ptr = CreateGroupIterator(this);
    ptr->first();
    for (ptr; ptr->hasNext(); ptr->next())
    {
        *(ptr->current())->print();
    }
    delete ptr; 
    cout << "====================================================================\n";
}

void CountryGroup::add(AlliedForce* ct){
    this.Allies.push_back(ct);
    ct.setAlliance(this);
    cout << ct->getName() << " has been added to " << this->getName() << "\n";
}

void CountryGroup::remove(AlliedForce* f){
    CountryGroupIterator* ptr = CreateGroupIterator(this);
    ptr->first();
    for (ptr; ptr->hasNext(); ptr->next())
    {
        if ((*(ptr->current()))->getName() == f->getName())
            this.Allies.erase(ptr);
    }
    delete ptr; 
}

void CountryGroup::~CountryGroup(){
    CountryGroupIterator* p = CreateGroupIterator(this);
    ptr->first();
    for (ptr; ptr->hasNext(); ptr->next()){
        if (*(ptr->current()) != NULL)
            delete (*ptr);
    }
    this.Allies.clear();
    delete p;
    this.Allies == NULL;
}

// CountryGroupIterator* CountryGroup::CreateGroupIterator(CountryGroup* c){
//     return new GroupIterator(c);
// }

// void CountryGroup::notify(){
// }

// void CountryGroup::attach(Observer warPhaseObserver){
// }

// void CountryGroup::detach(Observer parameter){
// }
