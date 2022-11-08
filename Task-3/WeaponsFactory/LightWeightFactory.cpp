#include "lightWeightFactory.h"
#include "../LightWeightWeapons/Grenades.h"
#include "../LightWeightWeapons/MachineGuns.h"
#include "../LightWeightWeapons/Rifles.h"
#include "../LightWeightWeapons/Pistols.h"

 /// @brief Produces Weapons based on the choice you have selected, the kind of weapon that you want
 /// @param choice Select what kind of Lightweight Weapon you want to produce
 /// @return an instance of the Weapon that you have created
 Weapons* LightWeightFactory::produceWeapons(int choice, int num, int budget)
 {

    while(true)
    {
        if(choice == 1)
        {
            if (num * 100 > budget)
            {
                cout << "Cannot afford to produce that many grenades!\n";
                return;
            }
            LightWeapons *wep = new Grenades(50, num, "Grenades");
            return wep;
        }
        else if(choice == 2)
        {
            if (num * 750 > budget){
                cout << "Cannot afford to produce that many rifles!\n";
                return;
            }
            LightWeapons *wep = new Rifles(60, num, "Rifles");
            return wep;
        }
        else if(choice == 3)
        {
            if (num * 1000 > budget)
            {
                cout << "Cannot afford to produce that many machine guns!\n";
                return;
            }
            LightWeapons *wep = new MachineGuns(70, num, "Machine Guns");
            return wep;
        }
        else if(choice == 4)
        {
            if (num * 300 > budget)
            {
                cout << "Cannot afford to produce that many pistols!\n";
                return;
            }
            LightWeapons *wep = new Pistols(30, num, "Pistols");
            return wep;
        }

        system("Color 4");
        cout << "Please Select an Option Between 1 - 4" << endl;
        system("Color 7");
    }
    
    
 }