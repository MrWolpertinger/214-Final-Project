#include "HighChanceObs.h"

/**
 * @brief Constructor of the class. Receives a War_Theatre* object and pass it to the constructor of its base class Obstacle.
 * @param A War_Theatre* object to be decorated;
*/
HighChanceObs::HighChanceObs(War_Theatre *W) : Obstacle(W){};

/**
 * @brief Description of the obstacle.
 * @return Description of the obstacle.
*/
std::string HighChanceObs::getDescription() {
    std::string sf, ss = "";
    int Type = Component->getType();
    switch (Type)//Doesn't work
    {
    case 1://air
        ss = " is engulfed in storms.";
        break;
    case 2://ground
        ss = " is mountainous.";
        break;
    case 3://sea
        ss = " is a sailors nightmare.";
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
War_Theatre* HighChanceObs::cloneTheatre(){
    return new HighChanceObs(Component);
}