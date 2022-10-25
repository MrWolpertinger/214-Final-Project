#ifndef WARPHASE_H
#define WARPHASE_H

#include<iostream>
using namespace std ;

class Country ;

class WarPhase {
    public:
   virtual void change(Country* c) = 0 ;
   virtual string getPhase() = 0 ;

};

class Intelligence : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class Initiation : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class Occupation : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class Finished : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};

class Neutral : public WarPhase {
    public:
    void change(Country* c) ;
    string getPhase() ;

};





#endif