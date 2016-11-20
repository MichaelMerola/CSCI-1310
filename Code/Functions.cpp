#include <iostream>

using namespace std;

// functions
// strings and chars
// input - output
// compiling
int addNumbers(int a, int b){
    return a + b;
}

double divNumbers (double a, double b){
    return a/b ;
}

int main(){

    cout<< "Hello World"<<endl;
    cout<< "Enter a number: ";

    int n;
    cin >> n;
    cin.ignore();

    cout<< "n = " << n << endl;

    string s;
    cout << "type a string: ";

    getline(cin, s, '\n');
    cout<< s << endl;

    // strings and chars
    string strA = "this is a string";
    int x = strA.find('a'); // finds the number associated with this character in the string
    cout<< x << endl;
        // strings have cool methods that do stuff!
    cout<< strA[x]<<endl; // returns whatever character is at that place

    // char
    char chrFoo[20]; //allocate space for 20 chars

    char chrWord[] = {'H', 'e', 'l', 'l', 'o', '\n'};

    cout<< chrWord[0]<<endl;
    cout<< chrWord[1]<<endl;
    cout<< chrWord[2]<<endl;

    cout<< endl;

    // functions
    int r = addNumbers(5, 6);
    cout<< r << endl;

    double d = divNumbers(14, 7);
    cout<< d << endl;

    return 0;
}
