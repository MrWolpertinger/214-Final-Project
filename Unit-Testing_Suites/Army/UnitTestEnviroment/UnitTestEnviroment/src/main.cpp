#include <iostream>
#include "Military.h"

int main() {
    Military *M = new Military();
    ArmyItorator* AI = M->createIterator();
    AI->add(new Navy(2,1,100));
    AI->add(new AirForce(2,1,100));
    std::cout << AI->getTotalHP() << AI->getTotalDMG() << std::endl;
    delete AI;
    return 0;
}