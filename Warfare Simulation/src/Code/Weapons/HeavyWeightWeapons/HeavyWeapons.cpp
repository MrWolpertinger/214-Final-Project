#include "HeaderFiles/HeavyWeapons.h"

/// @brief This is HeavyWeapons Constructor of which it calls the Weapons Constructor
/// with the following parameters
/// @param dam Damage of the weapon that will be set
/// @param name Name of the Weapon
HeavyWeapons::HeavyWeapons(int dam, int num, string name):Weapons(dam, num, name){}
