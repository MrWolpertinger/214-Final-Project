#include <string>

class War_Theatre {
protected:
    std::string _name;
    //CountryGroup* _SideA;
    //CountryGroup* _SideB;
    std::string _area;
    War_Theatre(const War_Theatre& Template);
public:
    War_Theatre(std::string n/*CountryGroup* SideA, CountryGroup SideB*/);
    ~War_Theatre() {};
    std::string getName();
    virtual War_Theatre* cloneTheatre();
    //CountryGroup* getSideA();
    //CountryGroup* getSideB();
};
