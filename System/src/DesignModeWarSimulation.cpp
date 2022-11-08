#include <iostream>
#include <string>
#include <algorithm>
#include "DesignModeWarSimulation.h"
#include "Battle.h"
#include "War_Theatre.h"
#include "Land_War_Theatre.h"
#include "Sea_War_Theatre.h"
#include "Airspace_War_Theatre.h"
#include "CountryFactory.h"
#include<cstdlib>

#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

DesignModeWarSimulation::DesignModeWarSimulation() {
	this->setUp();
}

DesignModeWarSimulation::~DesignModeWarSimulation() {
	
}

void DesignModeWarSimulation::setUp()
{
	// 1.) Scenario message.

	// 2.)coutry groups.

	CountryFactory* countryFactory=new CountryFactory(); //countries manufacturer.
	ConfigClass* c= ConfigClass::instance();
   	c->ParseConfigFile("../data/config.toml");
	CountryStruct* countryData;
	int noOfCountriesInput;

	string name;
	cout<<"Set the name of Country Group-A [SideA]\n";
	cout <<"Name: ";
	cin.ignore();
	getline(cin,name);
	CountryGroup *GroupA=new CountryGroup(name);
	
	cout << "How many countries are there in this country group?" << endl;
	cin >> noOfCountriesInput;

	for(int i=0;i<noOfCountriesInput;i++){
		countryData=c->getUniqueCountry();
		AlliedForce* c=countryFactory->createCountry(countryData->name,countryData->leaderName,countryData->TotalSpending);

		((Country*)c)->loadWeapons(countryData->NoOfWeapons);
		GroupA->add(c);
	}

	cout<<"Set the name of Country Group-B [SideB]\n";
	cout <<"Name: ";
	cin.ignore();
	getline(cin,name);
	CountryGroup *GroupB=new CountryGroup(name);

	cout << "How many countries are there in this country group?" << endl;
	cin >> noOfCountriesInput;

	for(int i=0;i<noOfCountriesInput;i++){
		countryData=c->getUniqueCountry();
			AlliedForce* c=countryFactory->createCountry(countryData->name,countryData->leaderName,countryData->TotalSpending);

		((Country*)c)->loadWeapons(countryData->NoOfWeapons);
		GroupB->add(c);
	}

	cout<<"Set the name of Country Group-C [Neutral Side(neightbouring countries and all)]\n";
	cout <<"Name: ";
	cin.ignore();
	getline(cin,name);
	CountryGroup *GroupC=new CountryGroup(name);

	cout << "How many countries are there in this country group?" << endl;
	cin >> noOfCountriesInput;

	for(int i=0;i<noOfCountriesInput;i++){
		countryData=c->getUniqueCountry();
			AlliedForce* c=countryFactory->createCountry(countryData->name,countryData->leaderName,countryData->TotalSpending);

		((Country*)c)->loadWeapons(countryData->NoOfWeapons);
		GroupC->add(c);
	}

	//Add the country Groups to their container.
	countryGroups[0]=GroupA;
	countryGroups[1]=GroupB;
	countryGroups[0]=GroupC;

}

void DesignModeWarSimulation::run()
{
	cout << "The war has begun." << endl;
	warIsActive = true;
	warloop();
}

void DesignModeWarSimulation::warloop(){
	cout << "\033[31m"
		 << "Warphase: Occupation"
		 << "\033[0m" << endl;
	/*int neutralJoinsWar= rand()%countryGroups[2]->Allies.size();
	if (isThereANeutralCountryGroup=="y" && neutralJoinsWar==0){
	   countryGroups[0]->add(countryGroups[2]->Allies.at(0));
	}*/

	string countryAStrategy, countryBStrategy;

	int time = 50;
	int x=0;
	int y=0;


	while (warIsActive){
		srand(1);

		time+=rand()%10;
		unsigned x=rand()%countryGroups[0]->Allies.size();
		Country* countryA = (Country*)countryGroups[0]->Allies[x];
		x=rand()%countryGroups[0]->Allies.size();
		Country* countryB = (Country*)countryGroups[1]->Allies[x];
		

		string countryChoiceA;
		string countryChoiceB;
		cout << "What would you like to do for country "<<countryA->getName()<<": \nAttack (A) \nRequest Assistance (R) \n Change Strategy (S) (A/R/S)";
		cin >> countryChoiceA;
		transform(countryChoiceA.begin(), countryChoiceA.end(), countryChoiceA.begin(), ::tolower);
		if (countryChoiceA == "a")
		{
			string warTheatreName,choice;
			War_Theatre* newWarTheatre;

			// 4.)choose a warTheatre.
			cout<<"Choose Your Desired War_Theatre (Default A): "<<endl;
			cout<<"A.) Land_War_Theatre."<<endl;
			cout<<"B.) Airspace_War_Theatre."<<endl;
			cout<<"C.) Sea_War_Theatre."<<endl;
			cin.ignore();
			getline(cin,choice);

			cout<<"Enter the name of your Theatre: ";
			getline(cin,warTheatreName);

			if(choice=="B" or choice=="b")
				newWarTheatre = new Airspace_war_theatre(warTheatreName,countryA,countryB);
			if(choice=="C" or choice=="c")
				newWarTheatre = new Sea_War_Theatre(warTheatreName,countryA,countryB);
			else
				newWarTheatre = new Land_War_Theatre(warTheatreName,countryA,countryB);
			
			Battle* newBattle = new Battle("Battle of "+warTheatreName, to_string(time), to_string(time+rand()%5),countryA,countryB,'L');
			newBattle->setLocal(newWarTheatre);
			
			cout<<newBattle->getBattleDescription();
			cout<<endl<<endl<<endl;

			countryA->attack(countryB);

			if(countryB->getHp()<=0){
				cout<<"Winner of the battle of "<<newBattle->getName()<<" is "<<countryA->getName()<<endl;
				x++;
				//countryGroups[1]->remove(countryB);
			}
			else{
				cout<<"Winner of the battle of "<<newBattle->getName()<<" is "<<countryB->getName()<<endl;
				//countryGroups[0]->remove(countryA);
				y++;
			}
			
			delete newBattle;
			check(x,y);
		}
		else if (countryChoiceA == "r"){
			countryA->requestAssistance();
		}else if (countryChoiceA == "s"){
			cout<<"What is the strategy for "<<countryA->getName()<<"(A/D/S)"<<endl;
			cin>>countryAStrategy;
			transform(countryAStrategy.begin(), countryAStrategy.end(), countryAStrategy.begin(), ::toupper);
			countryA->setCountryStrategy(countryAStrategy.at(0));
		}else if(countryChoiceA == "d"){
			
		}

		
	}
}

void DesignModeWarSimulation::check(int x,int y){
	if(countryGroups[0]->Allies.size()==x){
		cout<<"WAR ENDED....."<<endl<<endl;
		cout<<"Victor Group: "<<countryGroups[0]->getName()<<endl;
		warIsActive=false;
	}
	else if(countryGroups[1]->Allies.size()==y){
		cout<<"WAR ENDED....."<<endl<<endl;
		cout<<"Victor Group: "<<countryGroups[1]->getName()<<endl;
		warIsActive=false;
	}

}