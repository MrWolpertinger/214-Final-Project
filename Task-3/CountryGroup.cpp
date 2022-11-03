#include "CountryGroup.h"
using namespace std;

CountryGroup::CountryGroup(string name) : AlliedForce(name) {
    this->setCG(true);
    cout << name << " has been successfully created. \n";
};

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
    if (!(ct->CG())){
        cout << "Cannot add countries to other countries, only to other country groups.\n";
        return;
    }
    this.Allies.push_back(ct);
    ct.setAlliance(this);
    cout << ct->getName() << " has been added to " << this->getName() << "\n";
}

void CountryGroup::remove(AlliedForce* f){
    CountryGroupIterator* ptr = CreateGroupIterator(this);
    ptr->first();
    for (ptr; ptr->hasNext(); ptr->next())
    {
        AlliedForce* temp = ptr->current();
        if ((temp->getName() == f->getName()){
            this.Allies.erase(ptr);
            cout << temp->getName() << " is no longer part of " << this->getName() << "\n";
            break;
        }
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

AlliedForce* CountryGroup::getEnemy(){
    return this->enemy;
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