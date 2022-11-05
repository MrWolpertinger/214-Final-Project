#ifndef _COUNTRY_H
#define _COUNTRY_H
#include "AlliedForce.h"
#include "TransportationCorridor.h"
#include "Military.h"
#include "WeaponsInclude.h"
#include "CountryGroupIterator.h"
#include "CountryGroup.h"
#include "CountryStrategy.h"
#include "CountryStats.h"

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
        Weapons* arsenal;
        Military* _mil;
        TransportationCorridor* transportationCorridor;
        CountryGroup* myGroup;
        CountryStats* stats;

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
        void setCountryStrategy();
        string getStrategy();

        /////
        void increaseHP(int v) ;
        void support(Country* c);//added
        void setHP(int x);
        void setLeader(string l);
        void setNeutral(bool b);
        void setsurr(bool b);
        void setMil(Military* m);
};

#endif