#include<iostream>
#include "ConfigClass.h"
using namespace std;

int main(){
    ConfigClass::ParseConfigFile("config.toml");
	return 0;
}