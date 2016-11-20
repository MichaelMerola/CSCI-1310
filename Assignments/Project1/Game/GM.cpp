#include <iostream>
#include <stdlib.h>
#include <map>
#include "GM.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

//GM constructor
GM::GM()
{

}

void GM::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

Enemy spawnEnemy()
{
    int randInt = rand() % 5 + 1;
    Enemy multipEnemy(randInt);
    Enemy enemy;


    if (randInt == 3)
    {
        return multipEnemy;
    }
    else
    {
        return enemy;
    }
}

int GM::playerAttack()
{

    Enemy enemy = spawnEnemy();

    int damageToEnemy;
    int damageToPlayer;
    int totaldamagetoEnemy = 0;
    int totaldamagetoPlayer = 0;
    int hs;

    while (enemy.health > 0 and player.health > 0)
    {
        damageToEnemy = player.attackTerminal(player, enemy);
        damageToPlayer = enemy.attackPlayer();

        enemy.health -= damageToEnemy;
        player.health -= damageToPlayer;

        totaldamagetoEnemy += damageToEnemy;
        totaldamagetoPlayer += damageToPlayer;

    }//end while

    if (player.health <= 0)
        cout << "YOU DIED!!!" << endl;

    clearScreen();

    hs = totaldamagetoEnemy - totaldamagetoPlayer;

    return hs;
}

char GM::characterSelect()
{
    char playerID;
    bool charSelected = false;
    int charCursor = 0;
    int const totalCharacters = 3;//number of characters in game
    char cursorInput;

    map <int, char> characterMap;
    characterMap[0] = 'K';
    characterMap[1] = 'W';
    characterMap[2] = 'T';
    characterMap[3] = 'S';

    while (charSelected != true)
    {
        if (charCursor == 0)
        {
            cout << "Choose your character: " << endl;
            cout << endl;
            cout << "> Rob            Knight " << endl;
            cout << "  Jeremy         Wizard " << endl;
            cout << "  Fisher         Tank   " << endl;
            cout << "  Ava            Sniper " << endl;
            cout << endl;

        }//end cursor = 0
        else if (charCursor == 1)//show cursor in next position
        {
            cout << "Choose your character: " << endl;
            cout << endl;
            cout << "  Rob            Knight " << endl;
            cout << "> Jeremy         Wizard " << endl;
            cout << "  Fisher         Tank   " << endl;
            cout << "  Ava            Sniper " << endl;
            cout << endl;

        }//end cursor = 1
        else if (charCursor == 2)
        {
            cout << "Choose your character: " << endl;
            cout << endl;
            cout << "  Rob            Knight " << endl;
            cout << "  Jeremy         Wizard " << endl;
            cout << "> Fisher         Tank   " << endl;
            cout << "  Ava            Sniper " << endl;
            cout << endl;

        }//end cursor = 2
        else if (charCursor == 3)
        {
            cout << "Choose your character: " << endl;
            cout << endl;
            cout << "  Rob            Knight " << endl;
            cout << "  Jeremy         Wizard " << endl;
            cout << "  Fisher         Tank   " << endl;
            cout << "> Ava            Sniper " << endl;
            cout << endl;

        }//end cursor = 3

        cursorInput = cin.get();
        cin.ignore();

        switch (cursorInput)
        {
            case 'w':
                if (charCursor > 0)//move cursor to next line
                    charCursor -= 1;
                else if (charCursor == 0)//check boundaries of cursor
                    charCursor = 0;

                break;

            case 's':
                if (charCursor < totalCharacters)
                    charCursor += 1;
                else if (charCursor == totalCharacters)
                    charCursor = totalCharacters;

                break;

            case '\n':
                if (charCursor == 0)
                {
                    //k = Knight();
                    //player = &k;//set pointer to point to the address of this knight object
                    Knight player = k;

                    playerID = characterMap[0];//return character identifier based on map
                }
                else if (charCursor == 1)
                {
                    //player = &w;
                    Knight player = k;
                    playerID = characterMap[1];
                }
                else if (charCursor == 2)
                {
                    //player = &t;
                    Knight player = k;
                    playerID = characterMap[2];
                }
                else if (charCursor == 3)
                {
                    //player = &s;
                    Knight player = k;
                    playerID = characterMap[3];
                }

                charSelected = true;
                break;

            default:
                break;

        }//end switch
        clearScreen();
    }//end charSelected while
    return playerID;

}//end characterSelect



