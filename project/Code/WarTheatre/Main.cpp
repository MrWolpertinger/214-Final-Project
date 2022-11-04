#include <iostream>
#include "Battle.h"
#include "AlliedForce/HeaderFiles/Country.h"

int main(){
    std::cout << "Ground Force" << std::endl;
    Country* CA = new Country();
    Country* CB = new Country();
    Battle* BW = new Battle("B1","9","null",CA,CB,'A');//A/L/S
    std::string ss = BW->getBattleDescription();
    std::cout << ss << std::endl;
	return 0;
}