#include "lightWeightFactory.h"
#include "../LightWeightWeapons/Grenades.h"
#include "../LightWeightWeapons/MachineGuns.h"
#include "../LightWeightWeapons/Rifles.h"
#include "../LightWeightWeapons/MachineGuns.h"

 Weapons* LightWeightFactory::produceWeapons(int choice)
 {

    while(true)
    {
        if(choice == 1)
        {
            return new Grenades();
        }
        else if(choice == 2)
        {
            return new Rifles();
        }
        else if(choice == 3)
        {
            return new MachineGuns();
        }
        else if(choice == 4)
        {
            return new Grenades();
        }

        system("Color 4");
        cout << "Please Select an Option Between 1 - 4" << endl;
        system("Color 7");
    }
    
    
 }