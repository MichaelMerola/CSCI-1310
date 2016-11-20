#include <iostream>
using namespace std;

// Variable Type: Automobile
// Properties: top speed, current speed, size, color, price
// Behaviors: accelerate, turn, reverse

class Automobile
{
    //private, public
private:
    string make;
    string model;
    string condition;
    int year;

public:
    Automobile(string ma, string mo, int y)
    {
        // make, model, year
        make = ma;
        model = mo;
        year = y;
        condition = "new";

        cout << "calling constructor" << endl;
    }
    string getCondition()
    {
        return condition;
    }
    void setCondition(string c)
    {
        if(c == "new" or c == "used" or c == "wrecked")
            condition = c;
        else
            cout << "invalid" << endl;
    }
};


int main()
{
    Automobile prius ("Toyota", "Prius", 2010);

    cout << prius.getCondition() << endl;

    //set condition
    //new, used, wrecked
    prius.setCondition("used");
    cout << "Current condition: " << prius.getCondition()<<endl;

    return 0;
}
