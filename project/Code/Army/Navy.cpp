#include "HeaderFiles/Navy.h"

Navy::Navy() {

};

double Navy::getHP() {
    return _HPX/10*_Troops;
};

double Navy::getDMG() {
    return _DMGX/10*_Troops;
};

bool Navy::incHP(int T) {
    _Troops += T;
    return true;
};

bool Navy::decHP(int T) {
    if(_Troops - T <= 0) {
        return false;
    } else {
        _Troops -= T;
    }
};