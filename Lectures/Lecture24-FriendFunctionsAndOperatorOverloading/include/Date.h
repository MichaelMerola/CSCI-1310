#ifndef DATE_H
#define DATE_H

#include <iostream>
/*Consider a scenario where a Date object is taking data from multiple
sources, and each of those sources format the date differently. In some
cases, the date is separate integers, such as an int for month, day, year.
In other cases, date is a long int that needs to be parsed into a month,
day, and year. Or, the date might be a string, or even empty. Your
Date class needs to handle all of these cases
*/
class Date
{
    public:
        Date(int m, int d, int y);
        Date();
        Date(std::string s);
        ~Date();
        void showDate();
        int getMonth();
        int getDay();
        int getYear();
        friend bool compareDates(const Date& d1, const Date& d2);
        friend bool operator ==(const Date& d1, const Date& d2);
    protected:
        int month;
        int day;
        int year;

    private:
};

#endif // DATE_H
