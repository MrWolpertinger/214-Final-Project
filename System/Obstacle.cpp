#include "Obstacle.h"

/**
 * @brief Constructor of the class. Recieves the war_Theatre* object and assign it to component.
 * @param W A War_Theatre* object as the object being decorated.
*/
Obstacle::Obstacle(War_Theatre *W, AlliedForce* sideA, AlliedForce* sideB) {
    this->Component = W;
    this->_SideA = sideA;
    this->_SideB = sideB;
};

/**
 * @brief Destructor of the class. Deallocates the component variable. 
*/
Obstacle::~Obstacle() {
    if (this->Component != nullptr) {
        delete this->Component;
    }
};


AlliedForce* Obstacle::getSideA() {
    return _SideA;
};


AlliedForce* Obstacle::getSideB() {
    return _SideB;
};