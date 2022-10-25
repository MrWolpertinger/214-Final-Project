#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
using namespace std;

class Weapons
{
    private:
        string name;
        int damage;
    public:
        Weapons(int);
        Weapons(){};
        int fire();
        string getName();
        int getDamage();
        void setDamage(int);
        void setName(string name);
        ~Weapons(){};
};

#endif