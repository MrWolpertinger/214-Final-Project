#ifndef COUNTRYSTATS_H
#define COUNTRYSTATS_H
#include<iostream>
using namespace std;

class CountryStats{
    private:
        int refugeeCount;
        int enlistedCitizens;
        int deployedCitizens;
        int fightingCitizens;
        int stationedCitizens;
        int returnedCitizens;
        int deathtoll;
        int unlistedCitizens;
        long totalMilitarySpending;
    public:
    //getters
        int getRefugee();
        int getUnlisted();
        int getEnlisted();
        int getDeployed();
        int getFighting();
        int getStationed();
        int getReturned();
        int getDeath();
        long getBudget();

    //setters
        void setRefugee(int x);
        void setUnlisted(int x);
        void setEnlisted(int x);
        void setReturned(int x);
        void setDeath(int x);
        void setBudget(long x);
        void setDeployed(int x);
        void setFighting(int x);
        void setStationed(int x);

        void print();
};

#endif