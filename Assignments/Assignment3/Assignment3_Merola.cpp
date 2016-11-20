#include <iostream>

using namespace std;

int msgBoard [20][2];

string typeConvert(int type)
{
  switch (type)
  {
      case 1 :
          return "bike"; //int 1 is converted to bike

      case 2 :
          return "microwave"; // int 2 is converted to microwave

      case 3 :
          return "dresser"; //int 3 is converted to dresser

      case 4 :
          return "truck"; //int 4 is converted to truck

      case 5 :
          return "chicken"; //int 5 is converted to chicken

      default:
          break;
  }

} //end typeConvert

void addItem()
{
    char charType;
    int intType = 0;
    int cost = 0;
    int i = 0;
    bool itemPlaced = false;
    bool valid = true;

    cout << "Enter the item type (b, m, d, t, c): " << endl;
    cout << "b - bike \nm - microwave \nd - dresser \nt - truck \nc - chicken" << endl;
    cout << endl;

    cin >> charType;
    cin.ignore();
    cout << endl;

    // convert char to int
    switch (charType)
    {
        case 'b' :
            intType = 1; // bike is represented as 1 in the array, zero is empty
            valid = true;
            break;

        case 'm' :
            intType = 2; // microwave is represented as 2 in the array
            valid = true;
            break;

        case 'd' :
            intType = 3; // dresser is represented as 3 in the array
            valid = true;
            break;

        case 't' :
            intType = 4; // truck is represented as 4 in the array
            valid = true;
            break;

        case 'c' :
            intType = 5; // chicken is represented as 5 in the array
            valid = true;
            break;

        default:
            intType = 0;
            cout << "Invalid Type" << endl;
            cout << endl;
            valid = false;
            break;
    }

    if (valid == true)
    {
        cout << "Enter the item cost: " << endl;
        cin >> cost;
        cin.ignore();
        cout << endl;
        i = 0;

        while (itemPlaced != true)
        {
            if (msgBoard[i][0] == -1)// checks array for empty spot
            {
                msgBoard[i][0] = intType;
                msgBoard[i][1] = cost;

                itemPlaced = true; // item has been placed in the array
            }
            else
            {
                i++;
            }
        }

    } // end valid while
}// end addItem

void searchItem()
{
    char charType;
    int intType = 0;
    int maxCost = 0;
    int cost;
    int i = 0;

    bool itemFound = false;
    bool valid = true;

    string typeString ; //variable to store type as string


    cout << "Enter the item type (b, m, d, t, c): " << endl;
    cout << "b - bike \nm - microwave \nd - dresser \nt - truck \nc - chicken" << endl;
    cout << endl;

    cin >> charType;
    cin.ignore();
    cout << endl;

    // convert char to int
    switch (charType)
    {
        case 'b' :
            intType = 1; // bike is represented as 1 in the array, zero is empty
            valid = true;
            break;

        case 'm' :
            intType = 2; // microwave is represented as 2 in the array
            valid = true;
            break;

        case 'd' :
            intType = 3; // dresser is represented as 3 in the array
            valid = true;
            break;

        case 't' :
            intType = 4; // truck is represented as 4 in the array
            valid = true;
            break;

        case 'c' :
            intType = 5; // chicken is represented as 5 in the array
            valid = true;
            break;

        default:
            intType = 0;
            cout << "Invalid Type" << endl;
            cout << endl;
            valid = false;
            break;
    }

    if (valid == true)
    {
        cout << "Enter the max cost you will buy: " << endl;
        cin >> maxCost;
        cin.ignore();
        cout << endl;
        i = 0;

        while (itemFound != true)
        {
            if (msgBoard[i][0] == intType && msgBoard[i][1] <= maxCost)// checks array for item
            {
                intType = msgBoard[i][0];
                typeString = typeConvert(intType); //converts int to respective string
                cost = msgBoard[i][1];

                cout << "Sold " << typeString << " for $" << cost << endl;
                cout << endl;

                msgBoard[i][0] = -1;
                msgBoard[i][1] = -1;

                itemFound = true; // item has been found in the array
            }
            else if (i >= 20 && itemFound == false)
            {
                cout << "Item not found " << endl ;
                cout << endl;

                itemFound = true;
            }

            else
            {
                i++;
            }
        }

    } // end valid while
}

void printMsgBoard()
{
  int typeInt ; //variable to store type as an integer
  string typeString ; //variable to store type as string
  int cost ; //variable to store cost as int

  for (int i = 0; i < 20; i++)
  {
    if (msgBoard[i][1] != -1) // checks spot in the array
    {
        typeInt = msgBoard[i][0];
        typeString = typeConvert(typeInt); //converts int to respective string
        cost = msgBoard[i][1];

        cout << typeString << " : " << cost << endl;
    }
  }

  cout << endl;
}

int main()
{
    for (int i = 0; i < 20 ; i++)
    {
        msgBoard[i][0] = -1;
        msgBoard[i][1] = -1; //initialize all spots in the array to -1
    }

    int choice = 0;

    while (choice != 4)
    {
        cout << "1. Insert an item." << endl;
        cout << "2. Search for an item." << endl;
        cout << "3. Print the message board." << endl;
        cout << "4. Quit."<< endl;
        cout << endl;

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                addItem();
                break;

            case 2:
                searchItem();
                break;

            case 3:
                printMsgBoard();
                break;

            case 4:
                cout << "Goodbye!" <<endl;
                break;

            default:
                cout<< "Invalid input.." << endl;
                break;

        }// end switch


    }// end while

    return 0;

}// end main
