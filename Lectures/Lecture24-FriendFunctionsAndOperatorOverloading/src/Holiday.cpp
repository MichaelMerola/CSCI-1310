#include <iostream>
#include "Holiday.h"
#include "Date.h"

using namespace std;

Holiday::Holiday(std::string hName, int m, int d, int y):name(hName), Date(m, d, y)
{
    //ctor
}

Holiday::~Holiday()
{
    //dtor
}
void Holiday::showDate(){

    cout<<name<<"-"<<month<<"/"<<day<<"/"<<year<<endl;

}
