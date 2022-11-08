#include "Rifles.h"

/// @brief Rifles Constructor also sets the predetermined damage of the Rifles Weapons
/** 
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Rifles.
 * @param name [string] name of the weapon.
*/
Rifles::Rifles(int dmg,int num, string name):LightWeapons(dmg,num, name){
}