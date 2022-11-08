/**
 * @package "WarPhase.h". contains all the different warphase classes to indicate the phase of the war.
*/

#ifndef WARPHASE_H
#define WARPHASE_H
#include  "Country.h"
#include<iostream>
using namespace std;


class WarPhase {
    public:
   virtual void change(Country* c) = 0 ;
   virtual string getPhase() = 0 ;
   virtual ~WarPhase(){}

};

class IntelligencePhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;
    ~IntelligencePhase(){}

};

class InitiationPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;
    ~InitiationPhase(){}
};

class OccupationPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;
    ~OccupationPhase(){}
};

class FinishedPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;
    ~FinishedPhase(){}
};

class NeutralPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;
    ~NeutralPhase(){}
};





#endif