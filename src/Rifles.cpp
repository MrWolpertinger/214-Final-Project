#include "Rifles.h"

/// @brief Rifles Constructor also sets the predetermined damage of the Rifles Weapons
Rifles::Rifles(int dam, int num, string name):LightWeapons(dam, num, name){
    this->price = 750;
}