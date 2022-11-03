#include "Army.h"

class AirForce : public Army {
    public:
        AirForce();
        double getHP();
        double getDMG();
        bool incHP(int);//--
        bool decHP(int);//--
        char getType() {return _Type;};
    private:
        int _DMGX;
        int _HPX;
        int _Troops;
        const char _Type = 'A';
};