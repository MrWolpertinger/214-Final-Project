#include "LoChanceObs.h"

LoChanceObs::LoChanceObs(War_Theatre *W) : Obstacle(W){};

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