#include "Army.h"

class AirForce : public Army {
    public:
        AirForce(char);
        double getHP();
        double getDMG();
        bool incHP(int);//--
        bool decHP(int);//--
    private:
        int _DMGX;
        int _HPX;
        int _Troops;
};