#include "Submarines.h"


/// @brief Submarines Constructor also sets the predetermined damage of the Submarines Weapons
/** 
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Submarines.
 * @param name [string] name of the weapon.
*/
Submarines::Submarines(int dmg,int num, string name):HeavyWeapons(dmg,num, name) {}
