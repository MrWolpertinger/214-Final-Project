#ifndef ARMY_H
#define ARMY_H

class Army {
    public:
        Army(char type) {this->type=type;};
        virtual ~Army() {};
        int getID() { return id; };
        void setID(int i) { id = i; };
        virtual double getHP() = 0;//--
        virtual double getDMG() = 0;//--
        virtual char getType() {return type;};
        virtual bool incHP(int)=0;//--
        virtual bool decHP(int) =0;
    protected:
        int id;
        char type;

};

#endif // #ifndef ARMY_H