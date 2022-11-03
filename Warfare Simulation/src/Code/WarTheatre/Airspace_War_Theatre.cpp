#include "HeaderFiles/Airspace_war_theatre.h"

Airspace_war_theatre::Airspace_war_theatre(const Airspace_war_theatre& Template) : War_Theatre(Template){

};

Airspace_war_theatre::Airspace_war_theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/) : War_Theatre(name/*, SideA, SideB*/){

};

Airspace_war_theatre::~Airspace_war_theatre() {

};

War_Theatre* Airspace_war_theatre::cloneTheatre() {
    return new Airspace_war_theatre(*this);
};