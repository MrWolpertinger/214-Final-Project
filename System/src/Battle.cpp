#include "Battle.h"
/**
 * @brief The Constructor for the Battle class. It takes five paramaters to initialise it's member variables.
 * @param name Name of the battle.
 * @param startDate Start date of the battle.
 * @param endDate End date of the battle.
 * @param sideA country taking sideA of the war.
 * @param sideB country taking sideB of the war.
 * @param type type of warTheatre.
*/
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

/**
 * @brief destructor of the class. Deallocate memory for the _Locale member variable.
*/
Battle::~Battle() {
    delete _Locale;
};

/**
 * @brief A getter for the name of the battle.
 * @return name of the battle.
*/
std::string Battle::getName() {
    return _name;
};

/**
 * @brief A getter for the endDate of the battle.
 * @return endDate of the battle.
*/
std::string Battle::getEndDate() {
    return _endDate;
};

/**
 * @brief A getter for the startDate of the battle.
 * @return startDate of the battle.
*/
std::string Battle::getStartDate() {
    return _startDate;
};

/**
 * @brief The description of the battle. 
 * Call the description of the locale and get the names of the two sides and returns a description of the battle.
 * @return description of the battle.
*/
std::string Battle::getBattleDescription() {
    string des="Locale: "+_Locale->getDescription()+"\n";
    des+="Side A: "+_Locale->getSideA()->getName() +" VS Side B: "+_Locale->getSideB()->getName();
    return des;
};

/**
 * @brief A getter for the _Locale of the battle.
 * @return _Locale of the battle.
*/
War_Theatre* Battle::getLocal() {
    return _Locale;
};

/**
 * @brief A setter for the name of the battle.
 * @param name Name of the battle.
*/
void Battle::setName(std::string name) {
    _name = name;
};


/**
 * @brief A setter for the end date of the battle.
 * @param endDate end date of the battle.
*/
void Battle::setEndDate(std::string endDate) {
    _endDate = endDate;
};

/**
 * @brief A setter for the start date of the battle.
 * @param startDate start date of the battle.
*/
void Battle::setStartDate(std::string startDate) {
    _startDate = startDate;
};


/**
 * @brief A setter for the Locale of the battle.
 * @param Locale Locale of the battle.
*/
void Battle::setLocal(War_Theatre* Locale) {
    _Locale = Locale;
};