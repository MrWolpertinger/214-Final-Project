#ifndef ARMY_H
#define ARMY_H

class Army {
    public:
        virtual ~Army() {};
        int getID() { return id; };
        void setID(int i) { id = i; };
        virtual double getHP() = 0;//--
        virtual double getDMG() = 0;//--
        virtual char getType() {return 'X';};
        virtual bool incHP(int) {};//--
        virtual bool decHP(int) {};
    private:
        int id;
};

#endif // #ifndef ARMY_H