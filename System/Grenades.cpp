#include "Grenades.h"

/**
 * @brief grenade Constructor also sets the predetermined damage of the Grenade Weapons
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Grenades.
 * @param name [string] name of the weapon.
*/
Grenades::Grenades(int dmg,int num, string name):LightWeapons(dmg,num, name){}