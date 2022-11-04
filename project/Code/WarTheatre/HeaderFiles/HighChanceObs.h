#ifndef HIGHCHANCEOBS_H
#define HIGHCHANCEOBS_H
#include "Obstacle.h"

class HighChanceObs : public Obstacle
{
private:
    /* data */
public:
    HighChanceObs(War_Theatre *W);
    std::string getDescription();
};
#endif