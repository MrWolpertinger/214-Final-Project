
#include "Weapons.h"

string Weapons::getName()
{
    return name;
}
int Weapons::fire()
{
    return damage;
}

Weapons::Weapons(int damage, string NAME)
{
    this->damage = damage;
    this->setName(NAME);
}
int Weapons::getDamage()
{
    return damage;
}

void Weapons::setDamage(int damage)
{
    this->damage = damage;
}

void Weapons::setName(string name)
{
    this->name = name;
}