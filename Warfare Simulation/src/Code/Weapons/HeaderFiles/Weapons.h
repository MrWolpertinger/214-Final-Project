#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
using namespace std;

class Weapons
{
    private:
        string name;
        int damage;
        int price;
    public:
        Weapons(int,int,string);
        Weapons(){};
        int fire();
        string getName();
        int getDamage();
        void setDamage(int);
        void setName(string name);
        ~Weapons(){};
};

#endif
