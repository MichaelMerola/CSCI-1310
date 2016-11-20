#include "Date.h"
#include <iostream>
#include <sstream>

using namespace std;

/*Date constructor using an initialization list. This is different than
assigning values in the constructor once variables are created. This
initializes variables at the time of creation.
*/
Date::Date(int m, int d, int y):month(m), day(d), year(y)
{
    //ctor
    //month = m;
    //day = d;
    //year = y;
}

Date::Date(){
    month = 1;
    day = 1;
    year = 1990;
}

Date::Date(std::string date){
    //use stringstream to pull out date pieces
    //assumes date string formatted as m/d/y
    stringstream ss;
    ss<<date;
    std::string temp;
    getline(ss, temp, '/');
    month = stoi(temp);

    getline(ss, temp, '/');
    day = stoi(temp);

    getline(ss, temp, '/');
    year = stoi(temp);

}
Date::~Date()
{
    //dtor
}

void Date::showDate(){
    std::cout<<"The date is"<<std::endl;
    std::cout<<month<<"/"<<day<<"/"<<year<<std::endl;
}

int Date::getMonth(){
    return month;
}

int Date::getDay(){
    return day;
}

int Date::getYear(){
    return year;
}

/*This is the friend function compareDates. Notice that I can
access the protected variables, which isn't normally possible by
non-member function. But, since the function is a friend, it has
the same access as a member function.

Friend functions are great when you have multiple objects of the same
type that need to be used in the function. If we made it a member function,
we would still need accessor methods on the object we were comparing.

The parameters to the function in this example are passed as const parameters,
meaning that they can't be changed in the function. We're passign them by value,
which is what you get with the & operator. It can be much more efficient with
classes to pass a pointer, or pass by reference, than to pass by value.
*/

bool compareDates(const Date& d1, const Date& d2){
    bool datesEqual = false;
    if(d1.month == d2.month && d1.day == d2.day && d1.year == d2.year){
        datesEqual = true;
    }
    return datesEqual;
}

bool operator ==(const Date& d1, const Date& d2){
    return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

