#ifndef MEDCHANCEOBS_H
#define MEDCHANCEOBS_H
#include "Obstacle.h"

class MedChanceObs : public Obstacle
{
private:
    /* data */
public:
    MedChanceObs(War_Theatre *W);
    std::string getDescription();
    virtual War_Theatre* cloneTheatre();
};

#endif 