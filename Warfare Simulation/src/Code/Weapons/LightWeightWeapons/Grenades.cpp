#include "Grenades.h"

/// @brief grenade Constructor also sets the predetermined damage of the Grenade Weapons
Grenades::Grenades(int dam, int num, string name):LightWeapons(dam, num, name)
{
    this->price = 100;
}
