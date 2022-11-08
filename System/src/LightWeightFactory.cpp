#include "LightWeightFactory.h"


/**
 * @brief Produce a package of Grenade weapons.
 * @param damage [int] damage each Grenade inflict.
 * @param num [int] number of Grenades to produce.
*/
Weapons* LightWeightFactory::produceGrenades(int damage, int num){
    return new Grenades(damage,num,"Grenades");
}

/**
 * @brief Produce a package of MachineGun weapons.
 * @param damage [int] damage each MachineGun inflict.
 * @param num [int] number of MachineGuns to produce.
*/
Weapons* LightWeightFactory::produceMachineGuns(int damage, int num){
    return new MachineGuns(damage,num,"MachineGuns");
}

/**
 * @brief Produce a package of Pistol weapons.
 * @param damage [int] damage each Pistol inflict.
 * @param num [int] number of Pistols to produce.
*/
Weapons* LightWeightFactory::producePistols(int damage, int num){
    return new Pistols(damage,num,"Pistols");
}

/**
 * @brief Produce a package of Rifle weapons.
 * @param damage [int] damage each Rifle inflict.
 * @param num [int] number of Rifles to producse.
*/
Weapons* LightWeightFactory::produceRifles(int damage, int num){
    return new Rifles(damage,num,"Rifles");
}

