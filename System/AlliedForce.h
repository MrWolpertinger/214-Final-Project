#ifndef _ALLIEDFORCE_H
#define _ALLIEDFORCE_H
#include<iostream>
#include <string>

using namespace std;

class AlliedForce{
    protected:
        string name;
        bool isCG;
    public:
        AlliedForce(string name);
        virtual void print() = 0;
        virtual ~AlliedForce();
        void setCG(bool b);
        bool CG();
        virtual string getName();
};

#endif