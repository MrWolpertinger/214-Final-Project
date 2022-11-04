#ifndef _COUNTRYGROUP_H
#define _COUNTRYGROUP_H
#include "AlliedForce.h"
#include "Country.h"
#include <vector>

class CountryGroupIterator;
class CountryGroup : public AlliedForce{

    private:
        vector<AlliedForce*> Allies;
        CountryGroup* enemy;
    public:
        CountryGroup(string name);
        void print();
        void setEnemy(CountryGroup* e);
        AlliedForce* getEnemy();
        void add(AlliedForce* ptr);
        void remove(AlliedForce* ptr);
        CountryGroupIterator* CreateGroupIterator(vector<AlliedForce*> a);
        // void notify();
        // void attach(Observer warPhaseObserver);
        // void detach(Observer parameter);       
};

#endif
