#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "War_Theatre.h"

class Obstacle : public War_Theatre
{
protected:
    War_Theatre* Component;
public:
    Obstacle() {};
    Obstacle(War_Theatre *W, AlliedForce* sideA, AlliedForce* sideB);
    ~Obstacle();
    virtual std::string getDescription() = 0;//
    virtual War_Theatre* cloneTheatre()=0;
    AlliedForce* getSideA();
    AlliedForce* getSideB();
};
#endif