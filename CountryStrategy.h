#ifndef COUNTRYSTRATEGY_H
#define COUNTRYSTRATEGY_H
#include "Country.h"
#include <string>
#include<iostream>
using namespace std;

class CountryStrategy {

    public:
   
   virtual std::string getCountryStrategy() = 0 ;
    virtual ~CountryStrategy() ;

};


class Aggresive : public CountryStrategy{

    public:
    
    std::string getCountryStrategy() ;
    
    ~Aggresive() ;

};


class Defensive : public CountryStrategy {
    public:
    
    std::string getCountryStrategy() ;
   
     ~Defensive() ;

};

class Supportive : public CountryStrategy {
    public:
    
    std::string getCountryStrategy() ;
   
    ~Supportive() ;
};


#endif