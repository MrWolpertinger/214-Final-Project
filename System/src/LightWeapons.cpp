#include "LightWeapons.h"

/// @brief This is LightWeapons Constructor of which it calls the Weapons Constructor
/// with the following parameters.
/// @param dam Damage of the weapon that will be set.
/// @param num [int] number of a certain type of light weapon.
/// @param name Name of the Weapon.
LightWeapons::LightWeapons(int dam,int num,string name):Weapons(dam,num, name){}

