class Army {
    public:
        virtual bool add(Army* Force) = 0;
        virtual bool remove(Army* Force) = 0;
        virtual Army* get(int id) = 0;
        virtual ~Army();

        virtual void conflict() = 0;// the main function
};