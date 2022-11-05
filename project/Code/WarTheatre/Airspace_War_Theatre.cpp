#include "Airspace_War_Theatre.h"

Airspace_war_theatre::Airspace_war_theatre(const Airspace_war_theatre& Template) : War_Theatre(Template){};

Airspace_war_theatre::Airspace_war_theatre(std::string name, Country* SideA, Country* SideB) : War_Theatre(name, SideA, SideB){};

Airspace_war_theatre::~Airspace_war_theatre() {};

War_Theatre* Airspace_war_theatre::cloneTheatre() {
    return new Airspace_war_theatre(*this);
};

std::string Airspace_war_theatre::getDescription() {
    return "The sky";
};