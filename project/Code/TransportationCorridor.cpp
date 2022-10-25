#include "TransportationCorridor.h"


TransportationCorridor::TransportationCorridor(int cars, int buses, int trucks, int cargo_trains, int cargo_ships){
	_cars=cars;
	_cargo_trains=cargo_trains;
	_cargo_ships=cargo_ships;
	_trucks=trucks;
	_buses=buses;
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

