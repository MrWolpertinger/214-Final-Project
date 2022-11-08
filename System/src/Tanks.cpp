#include "Tanks.h"

/// @brief Tanks Constructor also sets the predetermined damage of the Tanks Weapons
/** 
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Tanks.
 * @param name [string] name of the weapon.
*/
Tanks::Tanks(int dmg,int num, string name):HeavyWeapons(dmg,num, name) {}