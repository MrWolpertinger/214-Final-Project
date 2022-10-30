#include "HeavyWeightFactory.h"
#include "../HeavyWeightWeapons/Warships.h"
#include "../HeavyWeightWeapons/Tanks.h"
#include "../HeavyWeightWeapons/Submarines.h"
#include "../HeavyWeightWeapons/Helicopters.h"

 Weapons* HeavyWeightFactory::produceWeapons(int choice)
 {

    while(true)
    {
        if(choice == 1)
        {
            HeavyWeapons *wep = new Warships();
            wep->setName("Warship");
            wep->setDamage(300);
            return wep;
        }
        else if(choice == 3)
        {
            HeavyWeapons *wep = new Tanks();
            wep->setName("Tank");
            wep->setDamage(400);
            return wep;
        }
        else if(choice == 2)
        {
            HeavyWeapons *wep = new Submarines();
            wep->setName("Submarine");
            wep->setDamage(350);
            return wep;
        }
        else if(choice == 4)
        {
            HeavyWeapons *wep = new Helicopters();
            wep->setName("Helicopter");
            wep->setDamage(200);
            return wep;
        }

        system("Color 4");
        cout << "Please Select an Option Between 1 - 4" << endl;
        system("Color 7");
    }
    
    
 }