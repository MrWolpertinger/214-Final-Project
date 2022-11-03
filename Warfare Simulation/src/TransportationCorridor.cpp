#include "TransportationCorridor.h"

/**
*@brief Constructor of the class. The Constructor initialise the number of different vehicles used for tranportation of trops and weapons.
* @param car [int] initial number of cars 
* @param buses [int] initial number of buses
* @param trucks [int] initial number of trucks
* @param cargo_trains [int] initial number of cargo_trains
* @param cargo_ships [int] initial number of cargo_ships
*/
TransportationCorridor::TransportationCorridor(int cars, int buses, int trucks, int cargo_trains, int cargo_ships){
	_cars=cars;
	_cargo_trains=cargo_trains;
	_cargo_ships=cargo_ships;
	_trucks=trucks;
	_buses=buses;
	check=true;
}

/**
*@brief Destructor of the class.
*/
TransportationCorridor::~TransportationCorridor(){
}


/**
*@brief Getter for the number of cars
*@return Number of cars
*/
int TransportationCorridor::get_num_cars() {
	return _cars;
}

/**
*@brief Getter for the number of buses
*@return Number of buses
*/
int TransportationCorridor::get_num_buses() {
	return _buses;
}

/**
*@brief Getter for the number of cargo_ships
*@return Number of cargo_ships
*/
int TransportationCorridor::get_num_cargo_ships() {
	return _cargo_ships;
}

/**
*@brief Getter for the number of trucks
*@return Number of trucks
*/
int TransportationCorridor::get_num_trucks() {
	return _trucks;
}

/**
*@brief Getter for the number of cargo_trains
*@return Number of cargo_trains
*/
int TransportationCorridor::get_num_cargo_trains() {
	return _cargo_trains;
}

/**
 * @brief Receives the damage paramater and substract it from all the different types of vehicles.
 * @param damage [int] damage inflicted by the opposing side on the transportation of this country.
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
 * @brief Get a total number of vehicles.
 * @return The sum total of all transpotation.
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
*@brief Display a defeat message after the whole Transportation corridor is defeated.
*/
void TransportationCorridor::defeat(){
	cout<<"Transpotation Corridor(supply chain) Destroyed"<<endl;
	check=false;
}