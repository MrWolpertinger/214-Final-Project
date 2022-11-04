#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include "War_Theatre.h"

class Battle
{
private:
    std::string _name, _startDate, _endDate, _battleDescription;
    War_Theatre* _Locale = nullptr;
public:
    Battle(std::string name, std::string startDate, std::string endDate, std::string battleDescription, /*CountryGroup* SideA, CountryGroup* SideB,*/ char type);
    ~Battle();
    void createWarTheatre(/*CountryGroup* A, CountryGroup* B*/);
    void setName(std::string name);
    void setEndDate(std::string endDate);
    void setStartDate(std::string startDate);
    void setBattleDescription(std::string battleDescription);
    void setLocal(War_Theatre* Locale);
    std::string getName();
    std::string getEndDate();
    std::string getStartDate();
    std::string getBattleDescription();
    War_Theatre* getLocal();
};

#endif // BATTLE_H