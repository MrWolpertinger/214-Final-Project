#include "Obstacle.h"

/**
 * @brief Constructor of the class. Recieves the war_Theatre* object and assign it to component.
 * @param W A War_Theatre* object as the object being decorated.
*/
Obstacle::Obstacle(War_Theatre *W) {
    this->Component = W;
};

/**
 * @brief Destructor of the class. Deallocates the component variable. 
*/
Obstacle::~Obstacle() {
    if (this->Component != nullptr) {
        delete this->Component;
    }
};