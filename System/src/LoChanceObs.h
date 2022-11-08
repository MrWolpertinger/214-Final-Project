#ifndef LOCHANCEOBS_H
#define LOCHANCEOBS_H
#include "Obstacle.h"

class LoChanceObs : public Obstacle
{
private:
    /* data */
public:
    LoChanceObs(War_Theatre *W);
    std::string getDescription();
    virtual War_Theatre* cloneTheatre();
};

#endif