#include "Pistols.h"

/// @brief Pistols Constructor also sets the predetermined damage of the Pistols Weapons
Pistols::Pistols(int dam, int num, string name):LightWeapons(dam, num, name)
{
    this->price = 300;
}