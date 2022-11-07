#include "Pistols.h"

/// @brief Pistols Constructor also sets the predetermined damage of the Pistols Weapons
/** 
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Pistols.
 * @param name [string] name of the weapon.
*/
Pistols::Pistols(int dmg,int num, string name):LightWeapons(dmg,num, name){}