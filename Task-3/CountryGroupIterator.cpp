#include "CountryGroupIterator.h"


CountryGroupIterator::CountryGroupIterator(std::vector<AlliedForce*> f){
    this->cg = f;
    this->it = cg.begin();
}

CountryGroupIterator::~CountryGroupIterator(){
    this->cg = NULL;
    this->it = NULL;
}

AlliedForce* CountryGroupIterator::first(){
    it = cg.begin();
    return (*it);
}
            
AlliedForce* CountryGroupIterator::next(){
    it++;
    return (*it);
}

AlliedForce* CountryGroupIterator::prev(){
    it--;
    return (*it);
}

bool CountryGroupIterator::hasNext(){
    it.next();
    if (it == cg.end()){
        it.prev();
        return false;
    }
    else{
        it.prev();
        return true;
    }
}
