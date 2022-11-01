#include "HeaderFiles/War_Theatre.h"

War_Theatre::War_Theatre(std::string name/*CountryGroup* SideA, CountryGroup SideB*/) {
    _name = name;
    /*_SideA = SideA;
    _SideB = SideB;*/
};

War_Theatre::War_Theatre(const War_Theatre& Template) {
    _name = Template._name;
    /*_SideA = Template._SideA;
    _SideB = Template._SideB*/
};

War_Theatre* War_Theatre::cloneTheatre() {
    return new War_Theatre(*this);
};

std::string War_Theatre::getName() {
    return _name;
};

/*CountryGroup* War_Theatre::getSideA() {
    return _SideA;
};

CountryGroup* War_Theatre::getSideB() {
    return _SideB;
};*/