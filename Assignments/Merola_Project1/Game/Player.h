#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Enemy.h"
using namespace std;

class Player
{
    protected:
        /*
        string name;
        char playerID;
        int level;      //Level of player
        int health;     //HP statistic
        int attack;     //Attack statistic
        int defense;    //Defense statistic

        double strength;//Damage multiplier
        double stance;  //Defense multiplier
        */

    public:
        //constructors
        Player();

        //variables
        string name;
        char playerID;
        int level;      //Level of player
        int health;     //HP statistic
        int attack;     //Attack statistic
        int defense;    //Defense statistic

        double strength;//Damage multiplier
        double stance;  //Defense multiplier

        //methods
        int attackTerminal();
        void clearScreen();

};

class Knight:public Player
{
    private:

    public:
        //constructors
        Knight();

        //methods
        int attackTerminal(Knight, Enemy);

};

class Wizard:public Player
{
    public:
        //constructors
        Wizard();

        //methods
        int attackTerminal();
};

class Tank:public Player
{
    public:
        //constructors
        Tank();

        //methods
        int attackTerminal();
};

class Sniper:public Player
{
    public:
        //constructors
        Sniper();

        //methods
        int attackTerminal();
};


#endif
