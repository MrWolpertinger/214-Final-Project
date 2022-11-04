#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include "Airspace_War_Theatre.h"
#include "Land_War_Theatre.h"
#include "Sea_War_Theatre.h"
#include "HighChanceObs.h"
#include "MedChanceObs.h"
#include "LoChanceObs.h"

class Battle
{
private:
    std::string _name, _startDate, _endDate;
    War_Theatre* _Locale = nullptr;
public:
    Battle(std::string name, std::string startDate, std::string endDate, Country* SideA, Country* SideB, char type);
    ~Battle();
    void setName(std::string name);
    void setEndDate(std::string endDate);
    void setStartDate(std::string startDate);
    void setLocal(War_Theatre* Locale);
    std::string getName();
    std::string getEndDate();
    std::string getStartDate();
    War_Theatre* getLocal();
    std::string getBattleDescription();//important
};

#endif // BATTLE_H