/** @file "Weapons.h". A base class of the weapon class. */
#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
using namespace std;

class Weapons
{
    private:
        string name; /**< name of the weapon.*/
        int damage; /**< damage the weapon can inflict*/
        int num; /** < the number of */
    public:
        Weapons(int,int,string);
        Weapons(){};
        virtual int fire();
        virtual string getName();
        virtual int getDamage();
        virtual int getTotalDamage();
        virtual void setDamage(int);
        virtual void setName(string name);
        virtual int getNum();
        virtual ~Weapons(){};
};

#endif