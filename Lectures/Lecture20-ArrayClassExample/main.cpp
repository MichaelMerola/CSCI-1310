#include <iostream>
#include "Array.h"
/*In this lecture, we're going to build an Array class that adds
features to the built-in C++ array. The data in our Array is
stored in a C++ array.

The things we want to do in the array are set values for a
specific index, print the data, append, delete, and insert.

In this example, we're fixing the size of the array to 30.
*/
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{

    Array myArray(0);
    cout<<"printing"<<endl;
    myArray.printData();

    myArray.appendData(5);
    cout<<"printing"<<endl;
    myArray.printData();

    myArray.appendData(15);
    cout<<"printing"<<endl;
    myArray.printData();

    cout<<"printing"<<endl;
    myArray.updateData(10, 10);
    myArray.printData();
    myArray.insertData(12,1);

    cout<<"printing"<<endl;
    myArray.printData();

    return 0;
}
