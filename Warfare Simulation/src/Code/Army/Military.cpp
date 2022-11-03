#include "HeaderFiles/Military.h"
#include "HeaderFiles/ArmyItorator.h"

Military::~Military() {
    std::vector<Army*>::iterator it;
    
    for (it = next.begin(); it != next.end(); ++it)
        delete *it;
};

ArmyItorator* Military::createItorator() {
    if(_Itorater != nullptr){
        return _Itorater;
    } else {
        _Itorater = new ArmyItorator(next);
        return _Itorater;
    }
};