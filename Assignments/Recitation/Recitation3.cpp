#include <iostream>

using namespace std;

int main(){

    int input;

    int mtEverest = 29029;
    int K2 = 28251;
    int Kang = 28169;

    cout<< "Enter a number: " << endl;
    cin>> input;

    if (input == mtEverest)
        cout<< input + " ft is the height of Mount Everest. It is the highest mountain." << endl;

    if (input == K2)
        cout<< input + " ft is the height of K2. It is the second highest mountain." << endl;

    if (input == Kang)
        cout<< input + " ft is the height of Kangchenjunga. It is the third highest mountain." << endl;

    else
        cout<< "Height does not match that of the three highest mountains. Please enter a correct height!!" << endl;

    return 0 ;
}
