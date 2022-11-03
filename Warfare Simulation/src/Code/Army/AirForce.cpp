#include "HeaderFiles/AirForce.h"

AirForce::AirForce() {

};

double AirForce::getHP() {
    return _HPX/10*_Troops;
};

double AirForce::getDMG() {
    return _DMGX/10*_Troops;
};

bool AirForce::incHP(int T) {
    _Troops += T;
    return true;
};

bool AirForce::decHP(int T) {
    if(_Troops - T <= 0) {
        return false;
    } else {
        _Troops -= T;
    }
};