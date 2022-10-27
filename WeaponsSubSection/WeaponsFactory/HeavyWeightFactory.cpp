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
            return new Warships();
        }
        else if(choice == 2)
        {
            return new Tanks();
        }
        else if(choice == 3)
        {
            return new Submarines();
        }
        else if(choice == 4)
        {
            return new Helicopters();
        }

        system("Color 4");
        cout << "Please Select an Option Between 1 - 4" << endl;
        system("Color 7");
    }
    
    
 }