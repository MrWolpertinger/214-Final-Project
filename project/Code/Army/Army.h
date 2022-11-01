#ifndef ARMY_H
#define ARMY_H

class Army {
    public:
        virtual ~Army() {};
        int getID() { return id; };
        void setID(int i) { id = i; };
        virtual void conflict() = 0;// the main function

    private:
        int id;
};

#endif // #ifndef ARMY_H