#include <iostream>
#include "Player.h"
#include "GM.h"
#include "Enemy.h"

using namespace std;

Enemy::Enemy()
{
    health = 50;
    attack = 1;
}

Enemy::Enemy(int healthMulti)
{
    health = healthMulti * health;
    attack = 2;
}

int Enemy::attackPlayer()
{
    return 4;
}
int attackAll()
{
    return 0;
}

void absorb(Enemy::boss B)
{

}
