#include <iostream>
#include <fstream> // file stream functionality
using namespace std;

int main()
{
    // iostream - cin , cout
    // fstream - filestream
    // ifstream - read-in file only
    // ofstream - write-out data
    // fstream - read and write, flags

    ofstream outFile;
    outFile.open("testFile.txt"); //creates the file if it doesn't exist
    outFile << "Hello World" << endl;

    // INVENTORY
    // mats - 39.95
    // bulbs - 3.22
    // fuses - 1.08

    outFile << "Inventory List" << endl;
    outFile <<  "Mats: " << 39.95 << endl;
    outFile << "Bulbs: " << 3.22 << endl;
    outFile << "Fuses: " << 1.08 << endl;
    outFile.close();

    // read in the file
    ifstream inFile ;
    inFile.open("testFile.txt");
    if (inFile.fail())
    {
        cout << "Something bad happened" << endl;
    }
    else
    {
        cout << "Process file here" << endl;
        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }

    // fstream
    fstream fs;
    string strLine;
    fs.open("testFile.txt", fstream::in | fstream::out | fstream::app);
    fs << "another line in the file" << endl;
    fs.clear();
    fs.seekg(0, ios::beg); // move fs to the beginning of the file

    while (getline(fs, strLine))
    {
        cout << strLine << endl;
    }
    fs.close();

    // count number of lines in the testToEnglish.csv file
    cout<<endl;

    fstream txt;
    string liner;
    int cc = 0;

    txt.open("textToEnglish.csv");

    if (txt.fail())
    {
        cout << "Something bad happened" << endl;
    }
    else
    {
        cout << "Process file here" << endl;
        while (getline(txt, liner))
        {
            cout << liner << endl;
            cc++;
        }
        cout<< cc << endl;
        txt.close();
    }

    return 0;
} // end main
