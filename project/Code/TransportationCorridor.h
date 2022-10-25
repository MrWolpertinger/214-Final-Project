#ifndef __TransportationCorridor_h__
#define __TransportationCorridor_h__
using namespace std;

class TransportationCorridor
{
	private: 
		int _cars;
		int _cargo_trains;
		int _cargo_ships;
		int _trucks;
		int _buses;
	public:
		TransportationCorridor(int, int, int, int, int);
		~TransportationCorridor();
		int get_num_cars();
		int get_num_buses();
		int get_num_cargo_ships();
		int get_num_trucks();
		int get_num_cargo_trains();
};

#endif
