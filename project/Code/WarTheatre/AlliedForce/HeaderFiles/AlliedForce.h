#ifndef _ALLIEDFORCE_H
#define _ALLIEDFORCE_H
#include<iostream>
#include <string>

using namespace std;

class AlliedForce{
    private:
        string name;
        bool isCG;
    public:
        AlliedForce(string name){
            this->name = name;
        }
        virtual void print() = 0;
        virtual void remove(AlliedForce* ptr);
        virtual ~AlliedForce() {};
        void setCG(bool b) {this->isCG = b;}
        bool CG() {return isCG;}
        string getName() {return name;}
};

#endif