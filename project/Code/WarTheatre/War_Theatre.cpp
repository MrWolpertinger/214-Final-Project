#include "HeaderFiles/War_Theatre.h"

War_Theatre::War_Theatre(std::string name, Country* SideA, Country* SideB) {
    this->_name = name;
    this->_SideA = SideA;
    this->_SideB = SideB;
};

War_Theatre::War_Theatre(const War_Theatre& Template) {
    this->_name = Template._name;
    this->_SideA = Template._SideA;
    this->_SideB = Template._SideB;
};

War_Theatre* War_Theatre::cloneTheatre() {
    return new War_Theatre(*this);
};

std::string War_Theatre::getName() {
    return this->_name;
};

void War_Theatre::setName(std::string name) {
    this->_name = name;
};

Country* War_Theatre::getSideA() {
    return this->_SideA;
};

Country* War_Theatre::getSideB() {
    return this->_SideB;
};

void War_Theatre::setSideA(Country* sideA) {
    this->_SideA = sideA;
};

void War_Theatre::setSideB(Country* sideB) {
    this->_SideB = sideB;
};

std::string War_Theatre::getArea() {
    return this->_area;
};

void War_Theatre::setArea(std::string area) {
    this->_area = area;
};
