#ifndef WARPHASE_H
#define WARPHASE_H
#include "Country.h"
#include<iostream>
using namespace std ;

class Country ;

class WarPhase {
    public:
   virtual void change(Country* c) = 0 ;
   virtual string getPhase() = 0 ;

};

class IntelligencePhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class InitiationPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class OccupationPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class FinishedPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class NeutralPhase : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};





#endif