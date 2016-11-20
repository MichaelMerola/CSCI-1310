#ifndef ARRAY_H
#define ARRAY_H

/*In the Array class, we have a c++ array for the data,
a size of the array, and a current index where elements
will be added if we want to append to the array.

The Array data is private. Accessing the array data
is done through public methods that allow us to control
how the data is added and to verify that the user is
making a valid request.
*/
class Array
{
    public:
        Array(int initVal);
        ~Array();
        void printData();
        void updateData(int, int);
        void appendData(int);
        void deleteData(int);
        void insertData(int, int);
    protected:
    private:
        int arrayData[30];
        int arraySize = 30;
        int currentIndex = 0;
};

#endif // ARRAY_H
