#ifndef __ConcreteObserver_h__
#define __ConcreteObserver_h__

#include "Observer.h"
#include "../../AlliedForce/HeaderFiles/countryGroup.h"

class ConcreteObserver: public Observer
{
	private: 
		WarPhase* _phase;
		CountryGroup* _subject;

	public: 
		void update();
};

#endif
