#include <iostream>
#include "Date.h"
#include "Holiday.h"

using namespace std;

bool compareDatesTheHardWay(Date d, Date d2){

    bool datesEqual = false;
    if(d.getDay() == d2.getDay() && d.getMonth() == d2.getMonth() && d.getYear() == d2.getYear()){
        datesEqual = true;
    }
    return datesEqual;
}

void displayDatesEqual(bool dEqual){

    if(dEqual == true){
        cout<<"dates are equal"<<endl;
    }else{
        cout<<"dates are not equal"<<endl;
    }

}

int main()
{
    Date d(12, 25, 2016);
    d.showDate();

    Date d2("1/20/1990");
    d.showDate();

    Holiday h("Christmas", 12, 25, 2016);
    h.showDate();

    /*How do we compare that two dates are equal? We could write a function
    that takes both objects as arguments, and then calls the public methods
    to access the month and day for each object and compare them. */
    bool datesEqual = compareDatesTheHardWay(d, d2);
    displayDatesEqual(datesEqual);

    datesEqual = compareDatesTheHardWay(d, h);
    displayDatesEqual(datesEqual);

    /*Another approach is to write a Friend function, which is a function that
    has access to private members of a class, but is not itself a member of the
    class. We declare the function in the class definition, but then implement the
    function outside of the class implementation. It is not a member of the class.*/
    datesEqual = compareDates(d, d2);
    displayDatesEqual(datesEqual);

    /*There's still another approach that uses operator overloading, where we can
    overload operators, such as +, =, and ==, to accept a class type as an argument.
    Instead of comparing individual fields in the Date to determine if the dates are
    equal, we want to say if d == d2. We need to overload the == operator to do this.
    */
    if(d == d2){
        cout<<"dates are equal"<<endl;
    }else{
        cout<<"dates are not equal"<<endl;
    }

    if(d == h){
        cout<<"dates are equal"<<endl;
    }else{
        cout<<"dates are not equal"<<endl;
    }
    /*We could also overload the + operator, but for this problem, it will mean
    adding dates together, and knowing how many days are in each month. Our
    overloaded method could take two dates, or a date and a number of days,
    depends on how we want to write it.*/
    return 0;
}
