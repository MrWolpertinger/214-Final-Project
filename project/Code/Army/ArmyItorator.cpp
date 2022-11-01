#include "HeaderFiles/ArmyItorator.h"

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