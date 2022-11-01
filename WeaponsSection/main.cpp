#include <iostream>
#include <vector>
using namespace std;

// Include files
#include "Weapons.h"
#include "WeaponsFactory/HeavyWeightFactory.h"
#include "WeaponsFactory/LightWeightFactory.h"
#include "WeaponsFactory/WeaponsFactory.h"



vector<Weapons*> CreateWeapons();

int main()
{
    vector<Weapons*> The_Weapons = CreateWeapons();
    cout << "Created "<< The_Weapons.size() << " Weapons" << endl;
    //get Damage of each of the weapons available

    for(int x = 0; x < The_Weapons.size(); x++)
    {
        cout << "Name: " << The_Weapons[x]->getName() << endl;
        cout << "Damage: " << The_Weapons[x]->getDamage() << endl;
    }

    return 0;
}

vector<Weapons*> CreateWeapons()
{
    vector<Weapons*> WeaponsVector;
    WeaponsFactory *HeavyWFac;
    WeaponsFactory *LightWFac;

    char Weapontype;
    cout << "Do you want to create LightWeight Weapons?" << endl;
    cout << "Y/N" << endl;
    cin >> Weapontype;

    if(Weapontype == 'Y' || Weapontype == 'y')
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


    cout << "Do you want to create HeavyWeight Weapons?" << endl;
    cout << "Y/N" << endl;
    cin >> Weapontype;
    if(Weapontype == 'Y' || Weapontype == 'y')
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
    return WeaponsVector;
}