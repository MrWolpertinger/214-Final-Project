#include <iostream>
#include <vector>
using namespace std;

// Include files
#include "Weapons.h"
#include "WeaponsFactory/HeavyWeightFactory.h"
#include "WeaponsFactory/LightWeightFactory.h"
#include "WeaponsFactory/WeaponsFactory.h"




int main()
{
    vector<Weapons*> WeaponsVector;
    WeaponsFactory *HeavyWFac = new HeavyWeightFactory();
    WeaponsFactory *LightWFac;

    char Weapontype;
    cout << "What kind of weapon do you want to create?" << endl;
    cout << "H -> HeavyWeapons" << endl;
    cout << "L -> LightWeapons" << endl;
    cin >> Weapontype;

    if(Weapontype == 'l' || Weapontype == 'L')
    {
        LightWFac = new LightWeightFactory();

        int GrenadesNum,MachineNum,RiflesNum,PistolNum;
        cout << "How many Grenades ?" << endl;
            cin >> GrenadesNum;
        cout << "How many MachineGuns ?" << endl;
            cin >> MachineNum;
        cout << "How many Rifles ?" << endl;
            cin >> RiflesNum;
        cout << "How many Pistols ?" << endl;
            cin >> PistolNum;

        

        //produce The Weapons into One Vector
        for(int x = 0 ;x < GrenadesNum; x++)
        {
            WeaponsVector.push_back(LightWFac->produceWeapons(1));
        }

        for(int x = 0 ;x < RiflesNum; x++)
        {
            WeaponsVector.push_back(LightWFac->produceWeapons(2));
        }

        for(int x = 0 ;x < MachineNum; x++)
        {
            WeaponsVector.push_back(LightWFac->produceWeapons(3));
        }

        for(int x = 0 ;x < PistolNum; x++)
        {
            WeaponsVector.push_back(LightWFac->produceWeapons(4));
        }

    }
    else if(Weapontype == 'h' || Weapontype == 'H')
    {
        HeavyWFac = new HeavyWeightFactory();

        int WarshipsNum,SubmarinesNum,Tanksnum,helicoptersNum;
        cout << "How many Warships ?" << endl;
            cin >> WarshipsNum;
        cout << "How many Submarines ?" << endl;
            cin >> SubmarinesNum;
        cout << "How many Tanks ?" << endl;
            cin >> Tanksnum;
        cout << "How many helicopters ?" << endl;
            cin >> helicoptersNum;

        

        //produce The Weapons into One Vector
        for(int x = 0 ;x < WarshipsNum; x++)
        {
            WeaponsVector.push_back(HeavyWFac->produceWeapons(1));
        }

        for(int x = 0 ;x < SubmarinesNum; x++)
        {
            WeaponsVector.push_back(HeavyWFac->produceWeapons(2));
        }

        for(int x = 0 ;x < Tanksnum; x++)
        {
            WeaponsVector.push_back(HeavyWFac->produceWeapons(3));
        }

        for(int x = 0 ;x < helicoptersNum; x++)
        {
            WeaponsVector.push_back(HeavyWFac->produceWeapons(4));
        }

    }
   


    cout << "Created "<< WeaponsVector.size() << " Weapons" << endl;

    return 0;
}
