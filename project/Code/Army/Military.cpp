#include "Military.h"

bool Military::add(Army* Force) {
    try {
        next.push_back(Force);
        return true;
    } catch (int i){
        return false;
    }
};

Army* Military::remove(int id) {
    std::vector<Army*>:: iterator it;
    int i = 0;
    Army* Temp = nullptr;;
    
    for (it = next.begin(); it != next.end(); ++it) {
        if(id == (*it)->getID()) {
            Temp = (*it);
            next.erase(next.begin() + i);
            return Temp;
        }
        i++;
    }
    return nullptr;
};

Army* Military::get(int id) {
    std::vector<Army*>:: iterator it;
    
    for (it = next.begin(); it != next.end(); ++it)
        if(id == (*it)->getID()) {
            return (*it);
        }
    return nullptr;
};

void Military::conflict() {};// the main function

Military::~Military() {
    std::vector<Army*>:: iterator it;
    
    for (it = next.begin(); it != next.end(); ++it)
        delete *it;
};
