#include <string>

class War_Theatre {
protected:
    std::string name;
    //CountryGroup* SideA;
    //CountryGroup* SideB;
    std::string area;
public:
    War_Theatre(/* args */);
    ~War_Theatre();
    std::string getName();
    virtual War_Theatre* cloneTheatre() = 0;
    //CountryGroup* getSideA();
    //CountryGroup* getSideB();
};
