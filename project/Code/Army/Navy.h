#include "Army.h"

class Navy : public Army{
    public:
        virtual void conflict();// the main function
    private:
        int Troops;
        int capacity;
};