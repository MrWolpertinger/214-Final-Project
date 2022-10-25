#include "Army.h"

class AirForce : public Army {
    public:
        virtual void conflict();// the main function
    private:
        int Troops;
        int capacity;
};