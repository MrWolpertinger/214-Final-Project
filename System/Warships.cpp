#include "Warships.h"

/// @brief Warships Constructor also sets the predetermined damage of the Warship Weapons
/** 
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Warships.
 * @param name [string] name of the weapon.
*/
Warships::Warships(int dmg,int num, string name):HeavyWeapons(dmg,num, name) {}
