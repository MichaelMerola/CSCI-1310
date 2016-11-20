#include <iostream>
using namespace std;

int a = 6; //global

// global variables
#define MPG 20.2 // macro, replace MPG with 20.2
#define STR "mySTR"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

const int intConst = 100; // constant, global

void scopeTest(){
    cout<<a<<endl;
}

int intSearch (int iSearch, int iLength, int arr[])
{
    bool found = false;
    int x = 0;
    iSearchIndex = -1;

    while(x < iLength && !found)
    {
        if (arr[x] == iSearch)
        {
            iSearchIndex = x;
            found = true;
        }
        x++;

        return x-1;
    }


}

int main(){
    int a = 5; // what is the scope of a? local to main, can be seen in main
    scopeTest();
    cout<<"inside main:"<<a<<endl;

    a++;
    cout<<"main: " <<a<<endl;
    scopeTest();

    cout<<endl;

    cout<<"mpg: "<<MPG<<endl;
    cout<< STR <<endl;

    cout<<endl;

    // arrays
    int intArray[10]; //array of ten integers
    cout<< "Array Stuff" << endl;

    for(int i = 0; i < 10; i++){
        intArray[i] = i;
        cout<<intArray[i]<<endl;
    }

    cout<<endl;

    string strArray[10];
    for(int i = 0; i < 10; i ++){
        strArray[i] = "string"  + i;
        cout<<strArray[i]<<endl;

    }

    //array operations
    // search
    int iSearch[6] = {4, 34, 23, 56, 67, 43};
    int iSearchVal = 56;
    int iSearchIndex = -1;
    int iLength = 6;
    bool found = false;
    int x = 0;
    while(x < iLength && !found)
    {
        if (iSearch[x] == iSearchVal)
        {
            iSearchIndex = x;
            found = true;
        }
        x++;
    }
    if (iSearchIndex != -1)
        cout<<"value found at index: "<< iSearchIndex<<endl;
    else
        cout<<"value not found"<<endl;

    // write a function called search that returns the index of a value in an array
    intSearch(int x);



    return 0;
}


int findMax(int x, int y)
{
    if (x > y)
        return x;
    else if (y > x)
        return y;
}


