#include "Military.h"

Military::Military(): Army('M'){
}

/**
 * @brief A destructor for the military class. Makes use of the iterator object to delete all the object contained in the military object.
*/
Military::~Military() {
    std::vector<Army*>::iterator it;
    
    for (it = next.begin(); it != next.end(); ++it)
        next.erase(it);
};

/**
 * @brief Creator function for the iterator.
 * @return Iterator of the army class.
*/
ArmyItorator* Military::createIterator() {
    if(_Iterator != nullptr){
        return _Iterator;
    } else {
        _Iterator = new ArmyItorator(next);
        return _Iterator;
    }
};


/*
 * @brief A getter fuction for the total sum of military damage of a country.
 * @return The total military damage inflicted by a country.
*
int Military::getMilitaryDamage(){
    int damage=0;
    std::vector<Army*>::iterator it;
    for (it = next.begin(); it != next.end(); ++it){
        damage+=(*it)->getDMG();
    }
    return damage;
}*/

bool Military::add(Army* element) {
    try {
        next.push_back(element);
    } catch (int i){
        return false;
    }
    return true; 
};

bool Military::remove(Army* element) {
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if(*itTemp == element) {
            next.erase(itTemp);
            return true;
        }
    }
    return false;
};

double Military::getDMG() {
    double TotalDMG = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        TotalDMG += (*itTemp)->getDMG();
    }
    return TotalDMG;
};

double Military::getHP() {
    double TotalHP = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        TotalHP += (*itTemp)->getHP();
    }
    return TotalHP;
};

bool Military::incHP(int){
    return true;
}

bool Military::decHP(int){
    return false;
}