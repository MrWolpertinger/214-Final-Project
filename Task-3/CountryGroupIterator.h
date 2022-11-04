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
        AlliedForce* first();
        AlliedForce* next();
        bool hasNext();
};

#endif
