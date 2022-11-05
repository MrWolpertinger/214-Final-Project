#include "MedChanceObs.h"

MedChanceObs::MedChanceObs(War_Theatre *W) : Obstacle(W){};

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