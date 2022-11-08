#include "MedChanceObs.h"

/**
 * @brief Constructor of the class. Receives a War_Theatre* object and pass it to the constructor of its base class Obstacle.
 * @param A War_Theatre* object to be decorated;
*/
MedChanceObs::MedChanceObs(War_Theatre *W, AlliedForce* sideA, AlliedForce* sideB) : Obstacle(W, sideA, sideB){};

/**
 * @brief Description of the obstacle.
 * @return Description of the obstacle.
*/
std::string MedChanceObs::getDescription() {
    std::string sf, ss = "";
    int Type = Component->getType();
    switch (Type)
    {
    case 1://air
        ss = " is difficult to fly in.";
        break;
    case 2://ground
        ss = " is difficult to move over.";
        break;
    case 3://sea
        ss = " is a bit choppy.";
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
War_Theatre* MedChanceObs::cloneTheatre(){
    return new MedChanceObs(Component, _SideA, _SideB);
}