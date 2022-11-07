#include "Navy.h"

/**
 * @brief The constructor class for the Navy class.
*/
Navy::Navy() {

}

/**
 * @brief A getter function for the health point of the Navy soldier.
 * @return A health point for the Navy Soldier.
*/
double Navy::getHP() {
    return _HPX/10*_Troops;
}
/**
 * @brief A getter function for the damage power of the Navy soldier.
 * @return A damage power for the Navy Soldier.
*/
double Navy::getDMG() {
    return _DMGX/10*_Troops;
};

/**
 * @brief A increase for the health point of the Navy Soldier.
 * @param T [int] increase value on the health point of the Navy soldier.
 * @return A bool value indicating if the increase occurred.
*/
bool Navy::incHP(int T) {
    _Troops += T;
    return true;
}

/**
 * @brief A decrease for the health point of the Navy Soldier.
 * @param T [int] decrease value on the health point of the Navy soldier.
 * @return A bool value indicating if the decrease occurred.
*/
bool Navy::decHP(int T) {
    if(_Troops - T <= 0) {
        return false;
    } else {
        _Troops -= T;
        return true;
    }
}