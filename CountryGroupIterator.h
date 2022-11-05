#ifndef COUNTRYGROUPITERATOR_H
#define COUNTRYGROUPITERATOR_H
#include <vector>

class AlliedForce;
class CountryGroupIterator

{
    private:
        std::vector<AlliedForce*> cg;
        std::vector<AlliedForce*>::iterator it;
    public:
        CountryGroupIterator(std::vector<AlliedForce*> f);
       
        ~CountryGroupIterator();
        AlliedForce* first();
        AlliedForce* next();
        AlliedForce* prev();
        AlliedForce* current();
        bool hasNext();
};

#endif