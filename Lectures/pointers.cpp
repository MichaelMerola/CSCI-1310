#include <iostream>
#include <stdlib.h>

using namespace std;

void  myFunction(int *x)
{
    // update the value of x
    cout << "you've arrived at function junction!!!1!!111!!!"<<endl;
    cout<<"address that x points to: "<<x<<endl;
    *x = 40;
}

int main ()
{
    string temp = "12";
    int x;
    x = atoi(temp.c_str());
    cout << x + 5 << endl;
    x = stoi(temp);
    cout<<x<<endl;

    // pointers
    cout << "address  of x" <<&x<< endl; // show address of x variable
    int *xPtr = &x ; // pointer to x
    cout <<"value of xPtr: " << *xPtr<<endl;

    cout<<endl;

    myFunction(xPtr);
    cout << "*xPtr after function: "<< *xPtr<<endl;
    cout << "x after function: " << &x << endl;

    return 0;
}
