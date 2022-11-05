#include "CountryGroup.h"
using namespace std;

CountryGroup::CountryGroup(string name) : AlliedForce(name) {
    this->setCG(true);
    cout << name << " has been successfully created. \n";
}

void CountryGroup::setEnemy(CountryGroup* e){
    this->enemy = e;
    cout << this->getName() << "'s enemy is now " << e->getName() << "\n";
}

void CountryGroup::print(){
    cout << "============================AllianceInfo============================\n";
    CountryGroupIterator* ptr = CreateGroupIterator();
    ptr->first();
    for (ptr; ptr->hasNext(); ptr->next())
    {
        (ptr->current())->print();
    }
    delete ptr; 
    cout << "====================================================================\n";
}

void CountryGroup::add(AlliedForce* ct){
    if (!(ct->CG())){
        cout << "Cannot add countries to other countries, only to other country groups.\n";
        return;
    }
    this->Allies.push_back(ct);
    ((Country*)ct)->setAlliance(this);
    cout << ct->getName() << " has been added to " << this->getName() << "\n";
}

void CountryGroup::remove(AlliedForce* f){
   vector<AlliedForce*>::iterator iter=Allies.begin();

    for (; iter!=Allies.end(); ++iter){
        if((*iter)==f)
            Allies.erase(iter);
    }
}

/*CountryGroup::~CountryGroup(){
    CountryGroupIterator* ptr = CreateGroupIterator();
    AlliedForce* p=ptr->first();
    for (ptr; ptr->hasNext(); ptr->next()){
        if (*(ptr->current()) != NULL)
            delete ptr;
    }
    this->Allies.clear();
    delete ptr;
    this->Allies = NULL;
}*/

AlliedForce* CountryGroup::getEnemy(){
    return this->enemy;
}

CountryGroupIterator* CountryGroup::CreateGroupIterator(){
    return new CountryGroupIterator(this->Allies);
}

// void CountryGroup::notify(){
// }

// void CountryGroup::attach(Observer warPhaseObserver){
// }

// void CountryGroup::detach(Observer parameter){
// }