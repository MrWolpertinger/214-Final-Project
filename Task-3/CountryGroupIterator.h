#ifndef COUNTRYGROUPITERATOR_H
#define COUNTRYGROUPITERATOR_H
#include <vector>

class AlliedForce;
class CountryGroupIterator
{
    private:
        std::vector<AlliedForce*> cg;
    public:
        CountryGroupIterator(std::vector<AlliedForce*> f);
        AlliedForce* first();
        AlliedForce* hasNext();
        AlliedForce* next();
};

#endif
