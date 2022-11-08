#include "CountryGroup.h"
using namespace std;

/**
 * @brief Constructor of the country group class. It takes the name paramater and pass it to its base class AlliedForce.
 * @param name name of the country group.
*/
CountryGroup::CountryGroup(string name) : AlliedForce(name) {
    this->setCG(true);
    cout << name << " has been successfully created. \n";
}

/**
 * @brief Setter of the enemy variable. The enemy is the opposing group.
 * @param e Enemy country group.
*/
void CountryGroup::setEnemy(CountryGroup* e){
    this->enemy = e;
    cout << this->getName() << "'s enemy is now " << e->getName() << "\n";
}


/**
 * @brief Print the description of the AlliedForce. Output information about all the countries in this group.
*/
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

/**
 * @brief Add a new member AlliedForce to the group and set its alliance to this group. 
 * @param ct a new country/ countryGroup member of this group.
*/
void CountryGroup::add(AlliedForce* ct){
    // if (!(ct->CG())){
    //     cout << "Cannot add countries to other countries, only to other country groups.\n";
    //     return;
    // }
    this->Allies.push_back(ct);
    ((Country*)ct)->setAlliance(this);
    cout << ct->getName() << " has been added to " << this->getName() << "\n";
}

/**
 * @brief removes a member of this countryGroup.
 * @param ct a country member of this group being removed.
*/
void CountryGroup::remove(AlliedForce* f){
   vector<AlliedForce*>::iterator iter=Allies.begin();

    for (; iter!=Allies.end(); iter++){
        if((*iter)==f)
            Allies.erase(iter);
    }
}

/**
 * @brief sets isNeutral variable
 * @param n isNeutral value
*/
void CountryGroup::setIsNeutral(bool n){
    isNeutral=n;
}

/**
 * @brief destructor of this class.
*/
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

/**
 * @brief A getter for the enemy(opposing country group) of this group.
 * @return An enemy member variable.
*/
AlliedForce* CountryGroup::getEnemy(){
    return this->enemy;
}

/**
 * @brief creates an iterator of this country group.
 * @return countryGroupIterator object.
*/
CountryGroupIterator* CountryGroup::CreateGroupIterator(){
    return new CountryGroupIterator(this->Allies);
}
/*
// void CountryGroup::notify(){
// }

// void CountryGroup::attach(Observer warPhaseObserver){
// }

// void CountryGroup::detach(Observer parameter){
// }
*/