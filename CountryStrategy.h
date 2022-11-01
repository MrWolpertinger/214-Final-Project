#ifndef COUNTRYSTRATEGY_H
#define COUNTRYSTRATEGY_H
#include "Country.h"

class CountryStrategy {

    public:
   virtual string getCountryStrategy() = 0 ;
    virtual ~CountryStrategy() ;

};


class Aggresive : public CountryStrategy{

    public:
    string getCountryStrategy() ;
    void Attack(Country* c) ;
    ~Aggresive() ;

};


class Defensive : public CountryStrategy {
    public:
    string getCountryStrategy() ;
    void Defend(Country* c) ;
     ~Defensive() ;

};

class Supportive : public CountryStrategy {
    public:
    string getCountryStrategy() ;
   // void Defend(Country* c) ;
    ~Supportive() ;
};


#endif