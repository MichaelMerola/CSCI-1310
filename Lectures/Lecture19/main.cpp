#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector <int>intVector;
    cout << intVector.size() << endl;
    intVector.push_back(78);
    intVector.push_back(88);
    intVector.push_back(98);

    for (int i = 0; i < intVector.size(); i++)
    {
        cout << intVector[i] << endl;
    }


    return 0;
}
