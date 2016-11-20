#include <iostream>
#include <math.h>

using namespace std;

int main(){
    cout<<"Hello world!" ;
    cout<< "hi again"<<endl;

    // variables
    // int - whole numbers
    // float, double - decimal numbers
    // strings - alphanumeric literals
    // char - single character
    // bool - true or false, 1 bit

    // define an integer
    int a = 5;
    cout<<a<<endl;

    int b = 6 ;
    cout << "b = " <<b<< endl;

    float c = 5.6;
    double e = 4.5;

    string x = "4.5" ;
    bool myBool = true;

    cout<<myBool<<endl;
    myBool = false;
    cout<<myBool<<endl;
    //addition on numbers
    int d = a +b;
    cout << "a+b = "<< d << endl;
    string z =  x + y;
    cout <<"z= " <<z<<endl;

    string s = "hello world";
    string s2 = "how are you";
    cout<< s + s2 << endl;
    //cout<< s + d << endl; error

    float f = c / e ;
    cout << f << endl;
    cout << a/b << endl; //int/int

    //multiplication
    double z2 = a * b ;
    cout << z2<< endl;

    //exponents
    // a^2, a ** 2
    z2 = pow(a, 2);
    cout<< z2 << endl;

    int z3 = a * c ;
    cout<< z3 << endl;

    float orNah = a * c ;
    cout<< orNah << endl;

    double z5 = a + (b * z3) / a ;
    // order of operations
    // (), *, /, %, +, -

    a = 75;
    b = 50;
    int v2 = a % b;
    cout << "c2 = " << c2 << endl;
    z5 = (double) a / b ;
    cout << z5 <<endl;

    return 0 ;
}
