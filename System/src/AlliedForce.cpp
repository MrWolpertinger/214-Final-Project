#include "AlliedForce.h"

/**
 * @brief The constructor of the class.
 * @param name the name of the allied force;
*/
AlliedForce::AlliedForce(string name){
	this->name = name;
}

/**
 * @brief The destructor of the class.
*/
AlliedForce::~AlliedForce() {}

/**
 * @brief
 * @param b
*/
void AlliedForce::setCG(bool b) {
	this->isCG = b;}

/**
 * @brief
 * @return 
*/
bool AlliedForce::CG() {
	return isCG;}

/**
 * @brief A getter for the name of the alliedForce.
 * @return the name of the AlliedForce.
*/
string AlliedForce::getName() {
	return name;}

