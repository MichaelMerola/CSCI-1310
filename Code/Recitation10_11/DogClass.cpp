#include <iostream>

using namespace std;


class Dog
{
    protected:
        string color, gender;
        int weight, skill;

    public:
        Dog (string color, string gender, int weight, int skill)
        {
            color = color;
            gender = gender;
            weight = weight;
            skill = skill;

        }

        void bark()
        {
            cout << "woof" << endl;
        }

        void rollOver()
        {
            if (skill > 10)
                cout << "roll, roll, roll!" << endl;
            else
                cout << "woof" << endl;
        }
 };

class Pug: public Dog
{
    public:
        Pug ()
        {}
        void bark()
        {
            cout << "ruff ruff!" << endl;
        }
        string showOff()
        {
            return color;
        }
};

class Lab: public Dog
{
    public:
        Lab()
        {}
        void bark()
        {
            cout << "growl!" << endl;
        }
        int giveWeight()
        {
            return weight;
        }
};

int main()
{
    Lab pupper ("Black", "Boy", 24, 400);
    pupper.bark();

    return 0;
}
