#include <iostream>
#include "Battle.h"
#include "Country.h"

int main(){
    srand(time(NULL));
    std::cout << "Ground Force" << std::endl;
    Country* CA = new Country();
    Country* CB = new Country();
    int tt = 0;
    while (tt <= 10) {
        Battle* BW = new Battle("B1","9","null",CA,CB,'A');//A/L/S
        std::string ss = BW->getBattleDescription();
        delete BW;
        std::cout << ss << std::endl;
        BW = new Battle("B1","9","null",CA,CB,'L');//A/L/S
        ss = BW->getBattleDescription();
        delete BW;
        std::cout << ss << std::endl;
        BW = new Battle("B1","9","null",CA,CB,'S');//A/L/S
        ss = BW->getBattleDescription();
        delete BW;
        std::cout << ss << "\n" << std::endl;
        tt++;
    }
    delete CA;
    delete CB;
	return 0;
}