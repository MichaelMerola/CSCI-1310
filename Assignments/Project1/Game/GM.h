#ifndef GM_H
#define GM_H

#include <iostream>
#include "Player.h"
using namespace std;

class GM
{
    private:
        Player *plPoint;

        Knight player;

        Knight k;
        Wizard w;
        Tank t;
        Sniper s;
    public:
        //constructors
        GM();

        //methods
        void clearScreen();
        char characterSelect();
        int playerAttack();


};

#endif
