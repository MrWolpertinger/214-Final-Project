#include "MachineGuns.h"

/** 
 * @brief MachineGuns Constructor also sets the predetermined damage of the MachineGuns Weapons
 * @param dmg [int] damage the weapon can inflict.
 * @param num [int] number of Machine Guns.
 * @param name [string] name of the weapon.
*/
MachineGuns::MachineGuns(int dmg,int num, string name):LightWeapons(dmg,num, name){
}

