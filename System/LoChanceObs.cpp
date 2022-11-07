#include "LoChanceObs.h"

/**
 * @brief Constructor of the class. Receives a War_Theatre* object and pass it to the constructor of its base class Obstacle.
 * @param A War_Theatre* object to be decorated;
*/
LoChanceObs::LoChanceObs(War_Theatre *W) : Obstacle(W){};

/**
 * @brief Description of the obstacle.
 * @return Description of the obstacle.
*/
std::string LoChanceObs::getDescription() {
    std::string sf, ss = "";
    int Type = Component->getType();
    switch (Type)
    {
    case 1://air
        ss = " is prime for flying.";
        break;
    case 2://ground
        ss = " is Perfect for movement.";
        break;
    case 3://sea
        ss = " is completely calm.";
        break;
    
    default:
        break;
    }
    sf = Component->getDescription();
    return (sf + ss);
};

/**
 * @brief clone fuction for the obstacle.
 * @return An clone instance of the current object.
*/
War_Theatre* LoChanceObs::cloneTheatre(){
    return new LoChanceObs(Component);
}