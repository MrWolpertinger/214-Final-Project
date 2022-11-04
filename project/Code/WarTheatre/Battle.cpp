#include "Battle.h"
#include "Airspace_war_theatre.h"
#include "Land_War_Theatre.h"
#include "Sea_War_Theatre.h"

Battle::Battle(std::string name, std::string startDate, std::string endDate, std::string battleDescription, /*CountryGroup* SideA, SideB*/ char type) {
    _name = name;
    _startDate = startDate;
    _endDate = endDate;
    _battleDescription = battleDescription;
    /*if(type == 'A') {
        _Locale = new Airspace_war_theatre()
    } else if(type == 'G') {

    } else {

    }*/
};

Battle::~Battle() {
    delete _Locale;
};

std::string Battle::getName() {
    return _name;
};

std::string Battle::getEndDate() {
    return _endDate;
};

std::string Battle::getStartDate() {
    return _startDate;
};

std::string Battle::getBattleDescription() {
    return _battleDescription;
};

War_Theatre* Battle::getLocal() {
    return _Locale;
};

void Battle::setName(std::string name) {
    _name = name;
};

void Battle::setEndDate(std::string endDate) {
    _endDate = endDate;
};

void Battle::setStartDate(std::string startDate) {
    _startDate = startDate;
};

void Battle::setBattleDescription(std::string battleDescription) {
    _battleDescription = battleDescription;
};

void Battle::setLocal(War_Theatre* Locale) {
    _Locale = Locale;
};