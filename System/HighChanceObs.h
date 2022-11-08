#ifndef HIGHCHANCEOBS_H
#define HIGHCHANCEOBS_H
#include "Obstacle.h"

class HighChanceObs : public Obstacle
{
private:
    /* data */
public:
    HighChanceObs(War_Theatre *W, AlliedForce* sideA, AlliedForce* sideB);
    std::string getDescription();
    War_Theatre* cloneTheatre();
};
#endif