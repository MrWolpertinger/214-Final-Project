#include "Weapons.h"

/// @brief Gets the private variable Name.
/// @return The private Viariable name which is a string datatype.
string Weapons::getName()
{
    return name;
}

/// @brief Gets the private variable damage, everytime you fire.
/// @return The private Viariable damage which is a int datatype.
int Weapons::fire()
{
    return damage;
}

/// @brief Constructor for the weapons class.
/// @param damage Damage that the weapon can cause.
/// @param NAME Name of the Weapon.
Weapons::Weapons(int damage,int num, string NAME)
{
    this->damage = damage;
    this->num=num;
    this->setName(NAME);
}

/// @brief Gets the private variable damage.
/// @return The private Viariable damage which is a int datatype.
int Weapons::getDamage()
{
    return damage;
}

/// @brief Sets the damage amount of the weapon
/// @param damage damage the weapon will cause
void Weapons::setDamage(int damage)
{
    this->damage = damage;
}

/// @brief Sets the name of the weapon
/// @param name Name of the weapon
void Weapons::setName(string name)
{
    this->name = name;
}


/// @brief Gets the private variable number of weapons.
/// @return The private Viariable num which is a int datatype.
int Weapons::getNum(){
    return num;
}

/// @brief Gets the total damage of a specific type of weapons.
/// @return damage*num.
int Weapons::getTotalDamage(){
    return damage*num;
}

void Weapons::addNum(int num){
    this->num+=num;
}