#include "HeaderFiles/ConcreteObserver.h"

/**
*
*/
void ConcreteObserver::update() {
	_phase=subject->getWarPhase();
}

