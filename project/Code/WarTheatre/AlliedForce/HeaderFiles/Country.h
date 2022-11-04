#ifndef _COUNTRY_H
#define _COUNTRY_H
#include "AlliedForce.h"
#include "CountryGroup.h"

class Country : public AlliedForce{

    private:
        string leader;
        AlliedForce* A = NULL;
        bool isNeutral;
        int unlistedCitizens;
        bool flag = false;
        int refugeeCount;
        int enlistedCitizens;
        int deployedCitizens;
        int fightingCitizens;
        int stationedCitizens;
        int returnedCitizens;
        int deathtoll;
        int HP;
        long totalMilitarySpending;
        //Weapon* arsenal;
        //TransportationCorridor* t;
        //string strategy;
        //WarPhase* phase;
    public:
        Country(string name);
        void attack(Country c);
        void setAlliance(AlliedForce* c);
        //void attack(TransportationCorridor tc);
        void requestAssistance(AlliedForce* cg);
        void receiveDamage(int amount);
        void print();
        void remove(AlliedForce* ptr);
        string getLeader();
        bool getNeutral();
        bool getsurr();
        int getRefugee();
        int getUnlisted();
        int getEnlisted();
        int getDeployed();
        int getFighting();
        int getStationed();
        int getReturned();
        int getDeath();
        int getHp();
        long getBudget();

        void setHP(int x);
        void setLeader(string l);
        void setNeutral(bool b);
        void setsurr(bool b);
        void setRefugee(int x);
        void setUnlisted(int x);
        void setEnlisted(int x);
        void setDeployed(int x);
        void setFighting(int x);
        void setStationed(int x);
        void setReturned(int x);
        void setDeath(int x);
        void setBudget(long x);
};

#endif