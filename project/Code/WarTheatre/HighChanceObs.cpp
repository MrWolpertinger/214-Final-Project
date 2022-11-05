#include "HighChanceObs.h"

HighChanceObs::HighChanceObs(War_Theatre *W) : Obstacle(W){};

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