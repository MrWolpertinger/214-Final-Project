#include "Land_War_Theatre.h"

Land_War_Theatre::Land_War_Theatre(const Land_War_Theatre& Template) : War_Theatre(Template){};

Land_War_Theatre::Land_War_Theatre(std::string name, Country* SideA, Country* SideB) : War_Theatre(name, SideA, SideB){};

Land_War_Theatre::~Land_War_Theatre() {};

War_Theatre* Land_War_Theatre::cloneTheatre() {
    return new Land_War_Theatre(*this);
};

std::string Land_War_Theatre::getDescription() {
    return "The terrain";
};