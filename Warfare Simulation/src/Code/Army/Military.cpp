#include "HeaderFiles/Military.h"
#include "HeaderFiles/ArmyItorator.h"

/**
 * @brief A destructor for the military class. Makes use of the iterator object to delete all the object contained in the military object.
*/
Military::~Military() {
    std::vector<Army*>::iterator it;
    
    for (it = next.begin(); it != next.end(); ++it)
        delete *it;
};

/**
 * @brief Creator function for the iterator.
 * @return Iterator of the army class.
*/
ArmyItorator* Military::createItorator() {
    if(_Itorater != nullptr){
        return _Itorater;
    } else {
        _Itorater = new ArmyItorator(next);
        return _Itorater;
    }
};