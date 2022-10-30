#include "lightWeightFactory.h"
#include "../LightWeightWeapons/Grenades.h"
#include "../LightWeightWeapons/MachineGuns.h"
#include "../LightWeightWeapons/Rifles.h"
#include "../LightWeightWeapons/Pistols.h"

 Weapons* LightWeightFactory::produceWeapons(int choice)
 {

    while(true)
    {
        if(choice == 1)
        {
            LightWeapons *wep = new Grenades();
            wep->setName("Grenade");
            wep->setDamage(50);
            return wep;
        }
        else if(choice == 2)
        {
            LightWeapons *wep = new Rifles();
            wep->setName("Rifle");
            wep->setDamage(60);
            return wep;
        }
        else if(choice == 3)
        {
            LightWeapons *wep = new MachineGuns();
            wep->setName("MachineGun");
            wep->setDamage(70);
            return wep;
        }
        else if(choice == 4)
        {
            LightWeapons *wep = new Pistols();
            wep->setName("Pistol");
            wep->setDamage(30);
            return wep;
        }

        system("Color 4");
        cout << "Please Select an Option Between 1 - 4" << endl;
        system("Color 7");
    }
    
    
 }