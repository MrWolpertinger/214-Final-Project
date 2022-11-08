#include "Army.h"

class GroundForce : public Army {
    public:
        GroundForce(char);
        double getHP();
        double getDMG();
        bool incHP(int);//--
        bool decHP(int);//--
    private:
        int _DMGX;
        int _HPX;
        int _Troops;
};