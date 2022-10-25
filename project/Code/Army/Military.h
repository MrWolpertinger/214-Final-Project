#include <vector>
#include "Army.h"

class Military : public Army{
    public:
        virtual bool add(Army* Force);
        virtual Army* remove(int id);
        virtual Army* get(int id);
        virtual void conflict();// the main function

        virtual ~Military();

    private:
        int numberOfTroops;
        std::vector<Army*> next;
};