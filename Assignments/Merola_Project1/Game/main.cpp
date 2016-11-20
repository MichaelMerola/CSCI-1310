#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>
#include "GM.h"
#include "Player.h"

using namespace std;

int playGame()
{
    GM gameManager;

    //variables
    char playerID;
    int highScore;
    string wait;

    playerID = gameManager.characterSelect(); //run character select and set player ID
    //create player object of whatever type chosen

    gameManager.clearScreen();//clear screen

    highScore = gameManager.playerAttack(); //create game screen

    gameManager.clearScreen();

    cout << "Your high score is " << highScore << "!!!!!!!!!" << endl;
    cout << "Did you have fun? "; cin >> wait;
    cin.ignore();

    gameManager.clearScreen();

    return highScore;
}

void newGame()
{
    int saveSlot = 1;
    int HS;
    ofstream saveFile;

    saveFile.open ("save_.txt"); //create a game save file
    saveFile << "SAVE GAME " << saveSlot << endl; // write save ID to file

    HS = playGame();

    saveFile << "High Score: " << HS << endl;

    saveFile.close();
}

void help()
{
    string wait;

    cout << "Use the 'w' key and the 's' key to navigate the cursor '>'" << endl;
    cout << "Press the enter key twice to confirm a choice" << endl;
    cout << endl;
    cout << "Choose your character and battle ASCII monsters!" << endl;
    cout << endl;

    cout << "Got it? ";
    cout << "(type anything to return to menu)" << endl;
    cin >> wait;
    cin.ignore();

    cout << "\033[2J\033[1;1H";
}

void joke()
{
    string wait;
    cout << "\033[2J\033[1;1H";//clear screen

    cout << "Knock, Knock" << endl;
    cin >> wait;
    cin.ignore();
    cout << "Play my game." << endl;
    cout << "(type anything to return to menu)" << endl;
    cin >> wait;
    cin.ignore();
    cout << "\033[2J\033[1;1H";//clear screen
}

int main()
{
    bool gameQuit = false;
    int mainChoice = 0;

    while (gameQuit != true)
    {
        cout << "ASCII BATTLE" << endl;    // Draw Menu
        cout << endl;
        cout << "(enter the corresponding number)" << endl;
        cout << "1. New Game " << endl;
        cout << "2. Help " << endl;
        cout << "3. Joke " << endl;
        cout << "4. Quit " << endl;

        cin >> mainChoice;
        cin.ignore();
        cout << "\033[2J\033[1;1H";//clear screen

        if (mainChoice == 1)
        {
            newGame();
        }
        else if (mainChoice == 2)
        {
            help();
        }
        else if (mainChoice == 3)
        {
            joke();
        }
        else if (mainChoice == 4)
        {
            gameQuit = true;
        }
        else
        {
            cout << "invalid input" << endl;
        }

    }//end menu while



    return 0;
}//end main



