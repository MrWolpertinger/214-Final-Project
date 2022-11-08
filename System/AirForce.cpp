#include "AirForce.h"

/**
 * @brief The constructor class for the AirForce class.
*/
AirForce::AirForce(int HPX, int DMGX, int Troops) {
    _HPX = HPX;
    _DMGX = DMGX;
    _Troops = Troops;
};

/**
 * @brief A getter function for the health point of the airForce soldier.
 * @return A health point for the airForce Soldier.
*/
double AirForce::getHP() {
    return _HPX*_Troops;
};

/**
 * @brief A getter function for the damage power of the airForce soldier.
 * @return A damage power for the airForce Soldier.
*/
double AirForce::getDMG() {
    return _DMGX*_Troops;
};

/**
 * @brief A decrease for the health point of the airForce Soldier.
 * @param T [int] decrease value on the health point of the airForce soldier.
 * @return A bool value indicating if the decrease occurred.
*/
bool AirForce::incHP(int T) {
    _Troops += T;
    return true;
};

/**
 * @brief A decrease for the health point of the airForce Soldier.
 * @param T [int] decrease value on the health point of the airForce soldier.
 * @return A bool value indicating if the decrease occurred.
*/
bool AirForce::decHP(int T) {
    if(_Troops - T <= 0) {
        return false;
    } else {
        _Troops -= T;
        return true;
    }
};