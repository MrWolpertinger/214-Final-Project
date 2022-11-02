#ifndef _ALLIEDFORCE_H
#define _ALLIEDFORCE_H
#include <string>

using namespace std;

class AlliedForce{
    private:
        string name;
    public:
        AlliedForce(string name){
            this.name = name;
        }
        virtual void print() = 0;
        virtual void remove() {AlliedForce* ptr};
        virtual ~AlliedForce() {};
        string getName() {return name};
};

#endif