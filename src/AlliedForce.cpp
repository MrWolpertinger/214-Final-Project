#include "AlliedForce.h"

AlliedForce::AlliedForce(string name){
	this->name = name;
}


AlliedForce::~AlliedForce() {}

void AlliedForce::setCG(bool b) {
	this->isCG = b;}

bool AlliedForce::CG() {
	return isCG;}
	
string AlliedForce::getName() {
	return name;}