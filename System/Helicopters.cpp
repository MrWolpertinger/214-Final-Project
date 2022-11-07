#include "Helicopters.h"


/**
 * @brief Helicopters Constructor also sets the predetermined damage of the Helicopters Weapons
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Helicopters.
 * @param name [string] name of the weapon.
*/
Helicopters::Helicopters(int dmg,int num, string name):HeavyWeapons(dmg,num, name) {}
