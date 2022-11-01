#include "War_Theatre.h"

class Land_War_Theatre : public War_Theatre
{
private:
    /* data */
public:
    Land_War_Theatre(/* args */);
    ~Land_War_Theatre();
    std::string getName();
protected:
    Land_War_Theatre(const Land_War_Theatre&);
};

Land_War_Theatre::Land_War_Theatre(/* args */)
{
}

Land_War_Theatre::~Land_War_Theatre()
{
}
