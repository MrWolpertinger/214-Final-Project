#include "GroundForce.h"

/**
 * @brief The constructor class for the GroundForce class.
*/
GroundForce::GroundForce() {

};

/**
 * @brief A getter function for the health point of the GroundForce soldier.
 * @return A health point for the GroundForce Soldier.
*/
double GroundForce::getHP() {
    return _HPX/10*_Troops;
};

/**
 * @brief A getter function for the damage power of the GroundForce soldier.
 * @return A damage power for the GroundForce Soldier.
*/
double GroundForce::getDMG() {
    return _DMGX/10*_Troops;
};

/**
 * @brief A decrease for the health point of the GroundForce Soldier.
 * @param T [int] decrease value on the health point of the GroundForce soldier.
 * @return A bool value indicating if the decrease occurred.
*/
bool GroundForce::incHP(int T) {
    _Troops += T;
    return true;
};

/**
 * @brief A decrease for the health point of the GroundForce Soldier.
 * @param T [int] decrease value on the health point of the GroundForce soldier.
 * @return A bool value indicating if the decrease occurred.
*/
bool GroundForce::decHP(int T) {
    if(_Troops - T <= 0) {
        return false;
    } else {
        _Troops -= T;
        return true;
    }
};