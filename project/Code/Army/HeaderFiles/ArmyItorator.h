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
        //overloading ++ & --
        Army* currentItem();
        bool add(Army* element);
        bool remove(Army* element);
        double getDMG(Army* element);//--
        double getTotalDMG();//--
        double getCatagoryDMG(Army* type);// for class comparison --
        double getHP(Army* element);//--
        double getTotalHP();//--
        double getCatagoryHP(Army* type);// for class comparison --
    
    private:
        std::vector<Army*>::iterator it;
        std::vector<Army*> next;
};


#endif // #ifndef ARMYITORATOR_H