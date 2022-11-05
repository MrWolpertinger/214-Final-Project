#ifndef _ALLIEDFORCE_H
#define _ALLIEDFORCE_H
#include <string>

using namespace std;

class AlliedForce{
    private:
        string name;
        bool isCG;
    public:
        AlliedForce(string name);
        virtual void print() ;
        virtual void remove(AlliedForce* ptr);
        virtual ~AlliedForce() ;
        void setCG(bool b) ;
        bool CG();
        string getName();
};



#endif