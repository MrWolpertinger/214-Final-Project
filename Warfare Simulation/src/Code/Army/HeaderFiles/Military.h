#include <vector>
#include <string>
#include "Army.h"
#include "ArmyItorator.h"

class Military : public Army{
    public:
        Military();
        ArmyItorator* createItorator();

        virtual ~Military();

    private:
        std::vector<Army*> next;
        ArmyItorator* _Itorater = nullptr;
};