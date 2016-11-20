#include <iostream>
using namespace std;

int sum (int x, int y)
{
    return x + y;
}

void sumPointer (int x, int y, int *ptr)
{
    *ptr = (x + y);
}

int main()
{
    int *ptr;
    int sum = sum(1, 2);

    cout << "sum = " << sum << endl;

    int x;
    *ptr = &x;

    cout << "address of x = " << *ptr << endl;

    sumPointer(1, 2, ptr);

    cout << suml << endl;

    return 0;
}
