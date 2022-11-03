#ifndef ARMYITORATOR_H
#define ARMYITORATOR_H
#include <vector>
#include "Army.h"

class ArmyItorator {
    public:
        ArmyItorator(std::vector<Army*> Force);
        Army* firstItem();
        Army* prevItem();
        Army* nextItem();
        Army* operator ++();
        Army* operator --();
        Army* currentItem();
        bool add(Army* element);
        bool remove(Army* element);
        double getDMG(Army* element);
        double getTotalDMG();
        double getCatagoryDMG(char type);
        double getHP(Army* element);
        double getTotalHP();
        double getCatagoryHP(char type);
        bool incHP(int);
        bool decHP(int);
        bool decHP(int, Army* element);
    private:
        std::vector<Army*>::iterator it;
        std::vector<Army*> next;
};


#endif // #ifndef ARMYITORATOR_H