#ifndef _COUNTRYGROUP_H
#define _COUNTRYGROUP_H
#include "AlliedForce.h"
#include "Country"
#include <list>

class CountryGroup : public AlliedForce{

    private:
        list<AlliedForce*> Allies;
        CountryGroup* enemy;
        string name;
    public:
        CountryGroup(string name);
        void print();
        void setEnemy(CountryGroup* e);
        void remove(AlliedForce* ptr);
        string getName();
        // void notify();
        // void attach(Observer warPhaseObserver);
        // void detach(Observer parameter);
        //CountryGroupIterator* CreateGroupIterator();
};

#endif