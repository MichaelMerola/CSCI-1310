#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct Word{
    string abbrev;
    string translate;
};

int main(){
    /*stringstream is a class where a string can be treated
    as a stream. Once it's a stream, it can be handled the same
    as other streams, such as iostream or fstream.*/

    int x = 1234;
    double y = 12.34;
    stringstream ss;

    ss<<x;
    /*can use stringstream for type conversions. Instead of
    stoi or atoi, or tostring(), we can put a variable in
    a stream and then take it out again.*/
    int z;
    ss>>z;
    cout<<z<<endl;
    /*but, now the stream has been read. We're at the end of
    the buffer, and if we continue reading,
    we don't any data.*/
    string z2;
    ss>>z2;
    cout<<z2<<endl;

    /*Back to the problem of reading in the file and parsing the
    contents. There was a funny line delimiter in the file and we
    need to use getline, with \r as the newline delimiter instead
    of the more-common \n.

    There is more information about newline vs. carriage return
    specifier on stackoverflow:
    http://stackoverflow.com/questions/1279779/what-is-the-difference-between-r-and-n
    */

    /*We have a few objectives with this problem:
    We want to read in the file, get the data, and
    store the data in a format that we can search later.
    I want to be able to query my data, meaning that
    I enter a text abbreviation, search the data, and if
    the abbreviation is found, return what it means, and if
    not found, say abbrev not found.*/

    /*We've talked about arrays, and in one
    assignment, we did a 2D array where each
    row in the array was some aspect of the data.
    In the message board assignment, one column
    was the type and the other column was the price.*/

    /*Another approach is to create a 1D array, where
    each element in the array is a compound variable.
    This is called a struct. The struct has a type that
    you create, and then within the type, are struct
    members, which also have a type. I defined a struct
    for this problem, called Word at the top of this file.
    The type Word has two members, an abbreviation and a translation.
    Both of the members of Word are strings*/

    /*I opened the file and so I know how many lines are in it.
    I'll create an array of words to handle everything in the file.
    The size of the array is the number of lines in the file. Next
    semester, we'll learn how to do this dynamically.*/
    int arrayLength = 4267;
    Word abbrev[arrayLength];

    /*control where we're writing to the array*/
    int wordIndex = 0;
    ifstream words;
    words.open("textToEnglish.csv");
    if(words.fail()){
        cout<<"file not found or something"<<endl;
    }
    else{
        string word;
        /*There is an index on this while loop that
        controls which line in the file we're reading,
        and which element in the struct we're updating.*/
        while(getline(words, word, '\r')){
            //word is the whole line
            cout<<word<<endl;
            //treat a string as a stream
            stringstream ss;
            ss<<word;
            /*ss looks like this:
            abbreviation, translation
            */

            /*use stringstream to convert the line
            into a stream, and then parse the stream.
            We use getline to read the stringstream,
            reading each word up to the comma.

            There is another index needed for looping over
            the contents of each line. We increase the index
            each time we hit a comma
            */
            int lineIndex = 0;
            while(getline(ss, word, ',')){
                cout<<word<<endl;
                /*On each line, I know that the
                first item is the abbreviation. We see this
                the first time through the loop when
                lineIndex = 0. The second time through the loop,
                we see the translation, which happens when
                lineIndex = 1.*/
                /*We can use wordIndex and lineIndex to
                populate the array.*/
                /*We could also take this whole thing out of a
                loop and just call getline twice, instead of
                putting it in a while loop.*/


                if(lineIndex == 0){
                    abbrev[wordIndex].abbrev = word;
                }else if(lineIndex == 1){
                    abbrev[wordIndex].translate = word;
                }
                lineIndex++;
            }
            wordIndex++;
        }
    }
    words.close();

    /*Test that we built the array correctly by printing it*/
    for(int i = 0; i < arrayLength; i++){
        cout<<abbrev[i].abbrev<<" "<<abbrev[i].translate<<endl;
    }
    //Exercise: write some code to search the array.
}
