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
}
            
AlliedForce* CountryGroupIterator::next(){
    it++;
}

AlliedForce* CountryGroupIterator::prev(){
    it--;
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

AlliedForce* CountryGroupIterator::current(){
    return (*it);
}
