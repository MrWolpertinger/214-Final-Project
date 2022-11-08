#include "Army.h"

class Navy : public Army{
    public:
        Navy(char);
        double getHP();
        double getDMG();
        bool incHP(int);//--
        bool decHP(int);//--
    private:
        int _DMGX;
        int _HPX;
        int _Troops;
};