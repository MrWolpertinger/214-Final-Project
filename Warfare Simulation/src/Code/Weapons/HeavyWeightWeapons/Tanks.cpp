#include "HeaderFiles/Tanks.h"

/// @brief Tanks Constructor also sets the predetermined damage of the Tanks Weapons
Tanks::Tanks(int dmg, int num, string name):HeavyWeapons(dmg, num, name) {}