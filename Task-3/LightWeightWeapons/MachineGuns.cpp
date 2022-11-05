#include "MachineGuns.h"

/// @brief MachineGuns Constructor also sets the predetermined damage of the MachineGuns Weapons
MachineGuns::MachineGuns(int dam, int num, string name):LightWeapons(dam, num, name){
    this->price = 1000;
}

