#include "Army.h"

class GroundForce : public Army {
    public:
        virtual void conflict();// the main function
    private:
        int numberOfTanks;
        int numberOfMortars;
        int armsCount;
};