#include "HeavyWeightFactory.h"


/**
 * @brief Produce a package of Tank weapons.
 * @param damage [int] damage each Tank inflict.
 * @param num [int] number of Tanks to produce.
*/
Weapons* HeavyWeightFactory::produceTanks(int damage, int num){
    return new Tanks(damage,num,"Tanks");
}

/**
 * @brief Produce a package of Warship weapons.
 * @param damage [int] damage each Warship inflict.
 * @param num [int] number of Warships to produce.
*/
Weapons* HeavyWeightFactory::produceWarships(int damage, int num){
    return new Warships(damage,num,"Warships");
}

/**
 * @brief Produce a package of Submarine weapons.
 * @param damage [int] damage each Submarine inflict.
 * @param num [int] number of Submarines to produce.
*/
Weapons* HeavyWeightFactory::produceSubmarines(int damage, int num){
    return new Submarines(damage,num,"Submarines");
}

/**
 * @brief Produce a package of Helicopters weapons.
 * @param damage [int] damage each Helicopters inflict.
 * @param num [int] number of Helicopters to producse.
*/
Weapons* HeavyWeightFactory::produceHelicopters(int damage, int num){
    return new Helicopters(damage,num,"Helicopters");
}