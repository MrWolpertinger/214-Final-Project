#ifndef OBSTACLE_H
#define OBSTACLE_H
# include "War_Theatre.h"

class Obstacle : public War_Theatre
{
protected:
    War_Theatre* Component;
public:
    Obstacle() {};
    Obstacle(War_Theatre *W);
    ~Obstacle();
    virtual std::string getDescription() = 0;//
};
#endif