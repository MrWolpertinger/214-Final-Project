#include <vector>
#include <string>
#include "Army.h"
#include "ArmyItorator.h"

class Military : public Army{
    public:
        //virtual bool add(Army* Force);
        //virtual Army* remove(int id);
        virtual void conflict();// the main function

        ArmyItorator* createItorator();

        virtual ~Military();

    private:
        int numberOfTroops;
        std::vector<Army*> next;
        std::string currWarTheatre;
};