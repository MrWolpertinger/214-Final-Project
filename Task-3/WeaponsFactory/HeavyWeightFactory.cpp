#include "HeavyWeightFactory.h"
#include "../HeavyWeightWeapons/Warships.h"
#include "../HeavyWeightWeapons/Tanks.h"
#include "../HeavyWeightWeapons/Submarines.h"
#include "../HeavyWeightWeapons/Helicopters.h"

 /// @brief Produces Weapons based on the choice you have selected, the kind of weapon that you want.
 /// @param choice Select what kind of Heavyweight weapon you want to produce.
 /// @return an instance of the weapon that you have created.
 Weapons* HeavyWeightFactory::produceWeapons(int choice, int num, int budget)
 {
    while(true)
    {
        if(choice == 1)
        {
            HeavyWeapons *wep = new Warships(300, num, "Warships");
            return wep;
        }
        else if(choice == 3)
        {
            HeavyWeapons *wep = new Tanks(400, num, "Tanks");
            return wep;
        }
        else if(choice == 2)
        {
            HeavyWeapons *wep = new Submarines(350, num, "Submarines");
            return wep;
        }
        else if(choice == 4)
        {
            HeavyWeapons *wep = new Helicopters(200, num, "Helicopters");
            return wep;
        }

        system("Color 4");
        cout << "Please Select an Option Between 1 - 4" << endl;
        system("Color 7");
    }
 }