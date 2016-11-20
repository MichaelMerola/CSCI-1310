
#include <iostream>
using namespace std;

// functions
int addNums (int a, int b)
{
    return a + b;
}

void printMsg(string msg)
{
    cout<<msg<<endl;
}

int main()
{
    int a;
    string helo = "hello world" ;
    double x = 4.5;

    cout<<"hello world"<<endl ;

    // conditionals and loops
    int intA = 5 ;
    if (intA < 5)
        cout<<"intA < 5"<<endl;
    else if (intA > 5)
        cout<<"intA > 5"<<endl;
    else
        cout<<"intA = 5"<<endl;

    int intB = 6;
        // conditional for when intA = 5 and intB = 6

    if (intA == 4 && intB == 6){
        cout<<"intA and intB"<<endl;
    }
    if (intA > 5 || intB == 6){
        cout<<"true that intA > 5 or intB = 6"<< endl;
    }
    else
        cout<<"Both are false"<<endl;

    int intCounter = 0;

    while (intCounter <= 5){
        cout<<intCounter<<endl;
        intCounter++;
    }
    for (int i = 0; i < 10 ; i++)
        cout<<"i = "<<endl;

    cout<<"i = "<<i<<endl;

}
