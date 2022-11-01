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
        Army* currentItem();
        bool add(Army* element);
        bool remove(Army* element);
    
    private:
        std::vector<Army*>::iterator it;
        std::vector<Army*> next;
};


#endif // #ifndef ARMYITORATOR_H