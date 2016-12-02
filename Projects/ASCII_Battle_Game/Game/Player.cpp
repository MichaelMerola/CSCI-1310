#include <iostream>
#include "Player.h"
#include "GM.h"

using namespace std;

//Constructors
Player::Player()
{

}

void Player::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}


int Player::attackTerminal()//overloaded by other classes
{

}//end attackTerminal

//Knight Constructor and Methods
Knight::Knight()
{
    name = "ROB";
    playerID = 'R';
    level = 1;
    health = 100;
    attack = 1;
    defense = 1;

    strength;
    stance;

}

int Knight::attackTerminal(Knight k, Enemy e)
{
    //Knight k;
    bool atkSelected = false;
    char cursorInput;
    int atkCursor = 0;
    int const totalAttacks = 2;

    int atk1_damage = 5 * k.attack;
    int atk2_damage = 3 * k.attack;
    int atk3_damage = 7 * k.attack;


    while (atkSelected != true)
    {
        clearScreen();

        string name = k.name;

        string atk1 = "SWORD SLASH: Slice the foe with a mighty swing of the sword ";
        string atk2 = "HEADBUTT: Damage the enemy by slamming your noggins (may cause concussions) ";
        string atk3 = "FIREBALL: Flaming sphere of hurt ";

        int khealth = k.health;
        int ehealth = e.health;
        char ID = k.playerID;

        cout << "////////////////////////////////////////////////////////" << endl;
        cout << "                                                        " << endl;
        cout << "                                                        " << endl;
        cout << "                                                        " << endl;
        cout << ID << "                                                        " << '@' << endl;//center
        cout << "                                                        " << endl;
        cout << "                                                        " << endl;
        cout << "                                                        " << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        cout << "                                                        " << endl;
        cout << name << " Health: " << khealth << "           Enemy Health: " << ehealth << endl;
        cout << "                                                        " << endl;

        if (atkCursor == 0)
        {

            cout << "ATTACK " << endl;
            cout << endl;
            cout << "> " << atk1 << endl;
            cout << "               ATK: 5" << endl;
            cout << "  " << atk2 << endl;
            cout << "               ATK: 3" << endl;
            cout << "  " << atk3 << endl;
            cout << "               ATK: 7" << endl;
            cout << endl;

        }//end cursor = 0
        else if (atkCursor == 1)//show cursor in next position
        {

            cout << "ATTACK " << endl;
            cout << endl;
            cout << "  " << atk1 << endl;
            cout << "               ATK: 5" << endl;
            cout << "> " << atk2 << endl;
            cout << "               ATK: 3" << endl;
            cout << "  " << atk3 << endl;
            cout << "               ATK: 7" << endl;
            cout << endl;

        }//end cursor = 1
        else if (atkCursor == 2)
        {

            cout << "ATTACK " << endl;
            cout << endl;
            cout << "  " << atk1 << endl;
            cout << "               ATK: 5" << endl;
            cout << "  " << atk2 << endl;
            cout << "               ATK: 3" << endl;
            cout << "> " << atk3 << endl;
            cout << "               ATK: 7" << endl;
            cout << endl;

        }//end cursor = 2

        cursorInput = cin.get();
        cin.ignore();

        switch (cursorInput)
        {
            case 'w':
                if (atkCursor > 0)//move cursor to next line
                    atkCursor -= 1;
                else if (atkCursor == 0)//check boundaries of cursor
                    atkCursor = 0;

                break;

            case 's':
                if (atkCursor < totalAttacks)
                    atkCursor += 1;
                else if (atkCursor == totalAttacks)
                    atkCursor = totalAttacks;

                break;

            case '\n':
                if (atkCursor == 0)
                {
                    return atk1_damage;
                }
                else if (atkCursor == 1)
                {
                    return atk2_damage;
                }
                else if (atkCursor == 2)
                {
                    return atk3_damage;
                }

                atkSelected = true;
                break;

            default:
                break;

        }//end switch

    }//end while
    k.clearScreen();
}
//end Knight Methods

Wizard::Wizard()
{
    name = "JEREMY";
    playerID = 'J';
    level = 1;
    health = 10;
    attack = 1;
    defense = 1;

    strength;
    stance;

}

Tank::Tank()
{
    name = "FISHER";
    playerID = 'F';
    level = 1;
    health = 10;
    attack = 1;
    defense = 1;

    strength;
    stance;

}

Sniper::Sniper()
{
    name = "AVA";
    playerID = 'A';
    level = 1;
    health = 10;
    attack = 1;
    defense = 1;

    strength;
    stance;

}
