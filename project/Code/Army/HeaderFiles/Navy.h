#include "Army.h"

class Navy : public Army{
    public:
        Navy();
        double getHP();
        double getDMG();
        bool incHP(int);//--
        bool decHP(int);//--
        char getType() {return _Type;};
    private:
        int _DMGX;
        int _HPX;
        int _Troops;
        const char _Type = 'N';
};