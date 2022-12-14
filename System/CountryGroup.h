#ifndef _COUNTRYGROUP_H
#define _COUNTRYGROUP_H
#include "Country.h"
#include <vector>

class CountryGroupIterator;
class CountryGroup : public AlliedForce{

    private:
        
        CountryGroup* enemy;
        bool isNeutral;


    public:
        CountryGroup(string name);
        void print();
        void setEnemy(CountryGroup* e);
        AlliedForce* getEnemy();
        void add(AlliedForce* ptr);
        void remove(AlliedForce* ptr);
        CountryGroupIterator* CreateGroupIterator();
        void setIsNeutral(bool);
        // void notify();
        // void attach(Observer warPhaseObserver);
        // void detach(Observer parameter);       

        vector<AlliedForce*> Allies;
};

#endif
