#include "ArmyItorator.h"

ArmyItorator::ArmyItorator(std::vector<Army*> Force) {
    it = next.begin();
};

Army* ArmyItorator::firstItem() {
    std::vector<Army*>::iterator itTemp;
    if(next.size() >= 0) {
        itTemp = next.begin();
        return *itTemp;
    }
    return nullptr;
};

Army* ArmyItorator::prevItem() {
    it--;

    return (*it);
};

Army* ArmyItorator::nextItem() {
    it++;

    return (*it);
};

Army* ArmyItorator::currentItem() {
    return (*it);
};

bool ArmyItorator::add(Army* element) {
    try {
        next.push_back(element);
    } catch (int i){
        return false;
    }
    return true; 
};

bool ArmyItorator::remove(Army* element) {
    std::vector<Army*>::iterator itTemp;
    for(itTemp = next.begin(); itTemp != next.end(); itTemp++) {
        if(*itTemp == element) {
            next.erase(itTemp);
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