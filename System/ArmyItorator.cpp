#include "ArmyItorator.h"

/**
 * @brief The constructor of the ArmyIterator. Takes in a vector of Army objects a create an iterator for those objects.
 * @param f A vector Army objects.
*/
ArmyItorator::ArmyItorator(std::vector<Army*> Force) {
    it = next.begin();
};

/**
 * @brief Points to the first Army* object.
*/
Army* ArmyItorator::firstItem() {
    std::vector<Army*>::iterator itTemp;
    if(next.size() >= 0) {
        itTemp = next.begin();
        return *itTemp;
    }
    return nullptr;
};

/**
 * @brief Points to the predecessor Army* object of the current.
*/
Army* ArmyItorator::prevItem() {
    it--;

    return (*it);
};

/**
 * @brief Points to the successor Army* object of the current.
*/
Army* ArmyItorator::nextItem() {
    it++;

    return (*it);
};

/**
 * @brief The current Army* object.
 * @return the current Army* object
*/
Army* ArmyItorator::currentItem() {
    return (*it);
};

bool ArmyItorator::add(Army* element) {
    try {
        next.push_back(element);
    } catch (int i){
        return false;
    }
    it = next.begin();
    return true; 
};

bool ArmyItorator::remove(Army* element) {
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if(*itTemp == element) {
            next.erase(itTemp);
            it = next.begin();
            return true;
        }
    }
    return false;
};

Army* ArmyItorator::operator --() {
    return this->prevItem();
};

Army* ArmyItorator::operator ++() {
    return this->nextItem();
};

double ArmyItorator::getTotalDMG() {
    double TotalDMG = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        TotalDMG += (*itTemp)->getDMG();
    }
    return TotalDMG;
};

double ArmyItorator::getDMG(Army* element) {
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if(element == *itTemp) {
            return (*itTemp)->getDMG();
        }
    }
    return 0;
};

double ArmyItorator::getCatagoryDMG(char type) {
    double TotalDMG = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if((*itTemp)->getType() == type) {
            TotalDMG += (*itTemp)->getDMG();
        }
    }
    return TotalDMG;
};//|||||||||||||||||||||||||||||||||

double ArmyItorator::getTotalHP() {
    double TotalHP = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        TotalHP += (*itTemp)->getHP();
    }
    return TotalHP;
};

double ArmyItorator::getHP(Army* element) {
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if(element == *itTemp) {
            return (*itTemp)->getHP();
        }
    }
    return 0;
};

double ArmyItorator::getCatagoryHP(char type) {//|||||||||||||||||||||||||||||||||||||||
    double TotalHP = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if((*itTemp)->getType() == type) {
            TotalHP += (*itTemp)->getHP();
        }
    }
    return TotalHP;
};


bool ArmyItorator::incHP(int hp) {// rounds down because of mortality of troops
    if(next.size() == 0) {
        return false;
    }
    int Number = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        Number++;
    }
    hp /= Number;

    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        (*itTemp)->incHP(hp);
    }
    return true;
};

bool ArmyItorator::decHP(int hp, Army* element) {// resets position of it
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if((*itTemp) == element) {
            if((*itTemp)->getHP() < hp) {
                this->remove((*itTemp));
                it = next.begin();
            } else {
                (*itTemp)->decHP(hp);
            }
            return true;
        }
    }
    return false;
};

bool ArmyItorator::decHP(int hp) {
    if(next.size() == 0) {
        return false;
    }    
    int Number = 0;
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        Number++;
    }
    hp /= Number;

    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if((*itTemp)->getHP() < hp) {
            this->remove((*itTemp));
            it = next.begin();
        } else {
            (*itTemp)->decHP(hp);
        }
    }
    return true;
};

//refresh it