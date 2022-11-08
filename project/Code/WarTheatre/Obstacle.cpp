#include "Obstacle.h"

Obstacle::Obstacle(War_Theatre *W) {
    this->Component = W;
};

Obstacle::~Obstacle() {
    if (this->Component != nullptr) {
        delete this->Component;
    }
};