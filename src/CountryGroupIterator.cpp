#include "CountryGroupIterator.h"


CountryGroupIterator::CountryGroupIterator(std::vector<AlliedForce*> f){
    this->cg = f;
    this->it = cg.begin();
}

CountryGroupIterator::~CountryGroupIterator(){
}

AlliedForce* CountryGroupIterator::first(){
    it = cg.begin();
    return *it;
}
            
AlliedForce* CountryGroupIterator::next(){
    it++;
    return *it;
}

AlliedForce* CountryGroupIterator::prev(){
    it--;
    return *it;
}

bool CountryGroupIterator::hasNext(){
   if(it!=cg.end())
        return true;
    return false;

}

AlliedForce* CountryGroupIterator::current(){
    return (*it);
}
