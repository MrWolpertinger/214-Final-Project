#include "CountryGroupIterator.h"


CountryGroupIterator::CountryGroupIterator(std::vector<AlliedForce*> f){
    this->cg = f;
    this->it = cg.begin();
}

CountryGroupIterator::~CountryGroupIterator(){
    for(AlliedForce* AL : cg)
    delete AL ;
    cg.clear();

    for(; it!= cg.end(); ){
        it = cg.erase(it);
    }
    

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
    it++;
    if (it == cg.end()){
        it--;
        return false;
    }
    else{
        it--;
        return true;
    }
}

AlliedForce* CountryGroupIterator::current(){
    return (*it);
}
