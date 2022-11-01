#ifndef _COUNTRY_H
#define _COUNTRY_H
#include "AlliedForce.h"
#include "CountryGroup.h"
#include "CountryStrategy.h"
//#include "WarPhase.h"

class Country : public AlliedForce{

    private:
        string leader;
        string name;
        AlliedForce* A = null;
        bool isNeutral;
        int unlistedCitizens;
        bool flag;
        int refugeeCount;
        int enlistedCitizens;
        int deployedCitizens;
        int fightingCitizens;
        int stationedCitizens;
        int returnedCitizens;
        int deathtoll;
        int HP;
        long totalMilitarySpending;
        WarPhase* phase;
        CountryStrategy* strategy;

        //Weapon* arsenal;
        //TransportationCorridor* t;
        //string strategy;
        //WarPhase* phase;
    public:
        Country(string name);
        void attack(Country c);
        void setAlliance(CountryGroup* c);
        //void attack(TransportationCorridor tc);
        void requestAssistance(CountryGroup cg);
        void increaseRandSpending(long amount);
        void receiveDamage(int amount);
        void print();
        void remove(AlliedForce* ptr);
        string getCurrentPhase();//getState
        void setWarPhase();
        void changeWarPhase();
        void setCountryStrategy();
        string getStrategy();
        
};

#endif