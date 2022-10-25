#include <vector>
#include "Army.h"

class Military : public Army{
    public:
        virtual bool add(Army* Force);
        virtual bool remove(Army* Force);
        virtual Army* get(int id);
        virtual void conflict();// the main function

        virtual ~Military();

    private:
        int Troops;
        int capacity;
        std::vector<Army*> next;
};