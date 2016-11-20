#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy
{
    public:
        int health;
        int attack;

        Enemy();
        Enemy(int healthMulti);
        int attackPlayer();

        class boss
        {
            public:
                boss();

                int health;

                int attackAll();
                friend void absorb(boss);

        };
};


#endif
