#include "Battle.h"

Battle::Battle(std::string name, std::string startDate, std::string endDate, Country* SideA, Country* SideB, char type) {
    this->_name = name;
    this->_startDate = startDate;
    this->_endDate = endDate;
    int chance = rand() % 3;
    if(chance == 0){
        if(type == 'A') {
            this->_Locale = new LoChanceObs(new Airspace_war_theatre(name, SideA, SideB));
        } else if(type == 'L') {
            this->_Locale = new LoChanceObs(new Land_War_Theatre(name, SideA, SideB));
        } else {
            this->_Locale = new LoChanceObs(new Sea_War_Theatre(name, SideA, SideB));
        }
    } else if(chance == 1) {
        if(type == 'A') {
            this->_Locale = new MedChanceObs(new Airspace_war_theatre(name, SideA, SideB));
        } else if(type == 'L') {
            this->_Locale = new MedChanceObs(new Land_War_Theatre(name, SideA, SideB));
        } else {
            this->_Locale = new MedChanceObs(new Sea_War_Theatre(name, SideA, SideB));
        }
    } else {
        if(type == 'A') {
            this->_Locale = new HighChanceObs(new Airspace_war_theatre(name, SideA, SideB));
        } else if(type == 'L') {
            this->_Locale = new HighChanceObs(new Land_War_Theatre(name, SideA, SideB));
        } else {
            this->_Locale = new HighChanceObs(new Sea_War_Theatre(name, SideA, SideB));
        }
    }
    
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
    return this->_Locale->getDescription();
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

void Battle::setLocal(War_Theatre* Locale) {
    _Locale = Locale;
};