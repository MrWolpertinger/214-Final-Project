#include "Sea_War_Theatre.h"

Sea_War_Theatre::Sea_War_Theatre(const Sea_War_Theatre& Template) : War_Theatre(Template){};

Sea_War_Theatre::Sea_War_Theatre(std::string name, Country* SideA, Country* SideB) : War_Theatre(name, SideA, SideB){};

Sea_War_Theatre::~Sea_War_Theatre() {};

War_Theatre* Sea_War_Theatre::cloneTheatre() {
    return new Sea_War_Theatre(*this);
};

std::string Sea_War_Theatre::getDescription() {
    return "The sea";
};