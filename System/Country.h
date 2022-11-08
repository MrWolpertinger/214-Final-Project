#ifndef _COUNTRY_H
#define _COUNTRY_H
#include "AlliedForce.h"
#include "TransportationCorridor.h"
#include "Military.h"
#include "CountryGroupIterator.h"
#include "CountryGroup.h"
#include "CountryStrategy.h"
#include "CountryStats.h"
#include "LightWeightFactory.h"
#include "HeavyWeightFactory.h"
#include<iostream>
using namespace std;

class WarPhase;
class CountryGroup;
class Country : public AlliedForce{

    private:
        string leader;
        AlliedForce* A = NULL;
        bool isNeutral;
        bool flag = false;
        int HP;
        WarPhase* phase;
        CountryStrategy* strategy;
        Military* _mil;
        TransportationCorridor* transportationCorridor;
        CountryGroup* myGroup;
        

    public:
        Country(string name);
        void attack(AlliedForce* c);
        void setAlliance(AlliedForce* c);
        void requestAssistance();
        void receiveDamage(int amount);
        void print();
        void remove(AlliedForce* ptr);
        string getLeader();
        bool getNeutral();
        bool getsurr();
        int getHp();
        void setStats();

        /////

        string getCurrentPhase();//getState
        void setWarPhase();
        void iteratePhases(WarPhase* phase_);
        void changeWarPhase();
        void setCountryStrategy(char answer);
        string getStrategy();

        /////
        void increaseHP(int v) ;
        void support(Country* c);//added
        void setHP(int x);
        void setLeader(string l);
        void setNeutral(bool b);
        void setsurr(bool b);
        void setMil(Military* m);
        void setTransportationCorridor(TransportationCorridor* t);

        void produceWeapons(int budget);
        int getArsenalDmg();

        // int refugeeCount;
		// int deployedCitizens;
		// int fightingCitizens;
		// int stationedCitizens;
		// int returnedCitizens;
		// int deathtoll;
        // int unlistedCitizens;
        // int enlistedCitizens;

        CountryStats* stats;
        Weapons** arsenal;
};

#endif