#ifndef KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_ENEMIES_H
#define KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_ENEMIES_H

#include "raylib.h"
#include "Animations.h"
#include "cmath"

struct oneEnemy {
    int enemyId;
    float x;
    float y;
    bool isAlive;
    bool damaged = false;
};

struct effectPosition {
    int frame = 0;
    bool var = false;
    Rectangle effectDes;
};

class Enemies {
public:
    Animations animations;

    Texture2D
        enemies = LoadTexture("../resources/image/enemies.png");

    Rectangle
        enemyRecMoss = { 0, 0, 89, 57 },
        enemyDesMoss = { 0, 28, 350, 229 },

        enemyRecMissile = { 0, 58, 89, 30 },
        enemyDesMissile = { 0, 0, 200, 76 },

        enemyRecBomb = { 403, 0, 74, 155 },
        enemyDesBomb = { 0, 640, 210, 440 },
        enemyRecBombEffect = { 29, 88, 47, 40 },

        enemyRecSailors = { 99, 0, 190, 155 },
        enemyDesSailors = { 0, 0, 0, 0 },

        enemyRecSpear = { 89, 0, 10, 128 },
        enemyDesSpear = { 0, 0, 0, 0 },

        enemyRecBarrel = { 289, 1, 114, 154 },
        enemyDesBarrel = { 0, 0, 0, 0 },
        enemyRecPoison = { 0, 88, 26, 40 },

        enemyRecList[6][2] = { enemyRecMoss, enemyDesMoss, enemyRecMissile, enemyDesMissile, enemyRecBomb, enemyDesBomb, enemyRecSailors, enemyDesSailors, enemyRecSpear, enemyDesSpear, enemyRecBarrel, enemyDesBarrel };

    Vector2
        origin = { 0, 0 };

    oneEnemy allEnemies[5];
    effectPosition allEffects[5];

    int currentEnemyCount = 0;
    int maxEnemyCount = 5;

    void initEnemies(int id);
    void reInitEnemies(int id);
    void drawEnemies(int id);

    bool didEnemiesCollide(oneEnemy enemy_1, oneEnemy enemy_2);
};


#endif //KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_ENEMIES_H
