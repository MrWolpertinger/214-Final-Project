#include <vector>
#include <string>
#include "Navy.h"
#include "GroundForce.h"
#include "AirForce.h"
#include "ArmyItorator.h"

class Military : public Army{
    public:
        Military();
        ArmyItorator* createIterator();
        int getMilitaryDamage();
        virtual ~Military();
        bool add(Army* element);
        bool remove(Army* element);
        double getTotalDMG();
        double getTotalHP();

    private:
        std::vector<Army*> next;
        ArmyItorator* _Iterator = nullptr;
};