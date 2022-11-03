#include "TransportationCorridor.h"


TransportationCorridor::TransportationCorridor(int cars, int buses, int trucks, int cargo_trains, int cargo_ships){
	_cars=cars;
	_cargo_trains=cargo_trains;
	_cargo_ships=cargo_ships;
	_trucks=trucks;
	_buses=buses;
	check=true;
}

TransportationCorridor::~TransportationCorridor(){
}


int TransportationCorridor::get_num_cars() {
	return _cars;
}

int TransportationCorridor::get_num_buses() {
	return _buses;
}

int TransportationCorridor::get_num_cargo_ships() {
	return _cargo_ships;
}

int TransportationCorridor::get_num_trucks() {
	return _trucks;
}

int TransportationCorridor::get_num_cargo_trains() {
	return _cargo_trains;
}

/**
 * @param damage [int] dameg inflicted by the opposing side on the transportation of this country.
 * 
*/
void TransportationCorridor::receiveDamage(int damage){
	if(check){
		_cars-=damage;
		_cargo_trains-=damage;
		_cargo_ships-=damage;
		_trucks-=damage;
		_buses-=damage;
		cout<<"Transpotation corridor attacked."<<endl;
		if(getTotal()<=0){
			defeat();
		}
	}
}

/**
 * @brief 
 * @returns [int] return the sum total of all transpotation
*/
int TransportationCorridor::getTotal(){
	int total=0;

	if(_cars>0)
		total+=_cars;
	if(_cargo_trains>0)
		total+=_cargo_trains;
	if(_cargo_ships>0)
		total+=_cargo_ships;
	if(_trucks>0)
		total+=_trucks;
	if(_buses>0)
		total+=_buses;
	
	return total;
}

/**
 * @brief 
*/
void TransportationCorridor::defeat(){
	cout<<"Transpotation Corridor(supply chain) Destroyed"<<endl;
	check=false;
}