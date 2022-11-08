#include "HeavyWeapons.h"
#include "Weapons.h"

/**
 * @brief This is HeavyWeapons Constructor of which it calls the Weapons Constructor
 * with the following parameters
 * @param dam Damage of the weapon that will be set
 * @param num [int] number of a certain type of heavy weapons.
 * @param name Name of the Weapon
*/
HeavyWeapons::HeavyWeapons(int dam,int num, string name):Weapons(dam,num, name){}
