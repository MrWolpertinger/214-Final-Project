#include "AlliedForce.h"
#include <iostream>

AlliedForce::AlliedForce(string name ){
    this->name = name ;
}

AlliedForce::~AlliedForce(){
    cout<<"" ;
}

void AlliedForce::setCG(bool b ){
    this->isCG = b;
}

bool AlliedForce::CG(){
    return isCG ;
}

string AlliedForce::getName(){
    return name ;
}

void AlliedForce::remove(AlliedForce* ptr){
    delete ptr ;
}

void AlliedForce::print(){
    cout << getName() << endl ;
}