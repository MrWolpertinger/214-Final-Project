#include "HeaderFiles/GroundForce.h"

GroundForce::GroundForce() {

};

double GroundForce::getHP() {
    return _HPX/10*_Troops;
};

double GroundForce::getDMG() {
    return _DMGX/10*_Troops;
};

bool GroundForce::incHP(int T) {
    _Troops += T;
    return true;
};

bool GroundForce::decHP(int T) {
    if(_Troops - T <= 0) {
        return false;
    } else {
        _Troops -= T;
    }
};