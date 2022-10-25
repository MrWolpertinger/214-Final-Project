class Army {
    public:
        virtual bool add(Army* Force) = 0;
        virtual bool remove(Army* Force) = 0;
        virtual Army* get(int id) = 0;
        virtual ~Army() {};
        int getID() { return id; };
        void setID(int i) { id = i; };
        virtual void conflict() = 0;// the main function

    private:
        int id;
};