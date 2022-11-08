#include "CountryGroupIterator.h"

/**
 * @brief The constructor of the countryGroupIterator. Takes in a vector of AlliedForce objects a create an iterator for those objects.
 * @param f A vector AlliedForce objects.
*/
CountryGroupIterator::CountryGroupIterator(std::vector<AlliedForce*> f){
    this->cg = f;
    this->it = cg.begin();
}

/**
 * @brief The default destructor of the CountryGroupIterator class.S
*/
CountryGroupIterator::~CountryGroupIterator(){
}

/**
 * @brief Points to the first AlliedForce* object.
*/
void CountryGroupIterator::first(){
    it = cg.begin();
    //return *it;
}

/**
 * @brief Points to the successor AlliedForce* object of the current.
*/
/*AlliedForce*/void CountryGroupIterator::next(){
    it++;
    //return *it;
}

/**
 * @brief Points to the predecessor AlliedForce* object of the current.
*/
/*AlliedForce*/void CountryGroupIterator::prev(){
    it--;
    //return *it;
}

/**
 * @brief Check if there is a next AlliedForce* object.
 * @return A boolean value to indicate if the is a next object.
*/
bool CountryGroupIterator::hasNext(){
   if(it!=cg.end())
        return true;
    return false;

}

/**
 * @brief The current AlliedForce* object.
 * @return the current AlliedForce* object
*/
AlliedForce* CountryGroupIterator::current(){
    return (*it);
}
