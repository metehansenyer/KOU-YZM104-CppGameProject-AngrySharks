#include "Enemies.h"

void Enemies::initEnemies(int id) {
    if (currentEnemyCount < maxEnemyCount) {
        int enemy_id = rand() % 2;
        int x = (rand() % GetScreenWidth()) + GetScreenWidth();

        int y;

        if (id == 3) {
            enemy_id += 1;
            y = (rand() % (GetScreenHeight() - 260) + 260);

            if (enemy_id == 2) {
                y = (int) enemyRecList[enemy_id][1].y;
            }
        } else {
            y = (rand() % (GetScreenHeight() - 217) + 217);

            if (enemy_id == 0) {
                y = (int) enemyRecList[enemy_id][1].y;
            }
        }

        oneEnemy enemy = {enemy_id, (float) x, (float) y, true};

        allEnemies[currentEnemyCount] = enemy;
        currentEnemyCount++;

        bool control = false;

        if (currentEnemyCount == maxEnemyCount) {
            for (int i = 0; i < currentEnemyCount; ++i) {
                for (int j = 0; j < currentEnemyCount; ++j) {
                    if (i != j) {
                        if (didEnemiesCollide(allEnemies[i], allEnemies[j])) {
                            control = true;
                        }
                    }
                }
            }
        }

        if (control) {
            currentEnemyCount = 0;
            control = false;
        }
    }
}

void Enemies::reInitEnemies(int id) {
    if (currentEnemyCount == maxEnemyCount) {
        for (int i = 0; i < currentEnemyCount; ++i) {
            if (!allEnemies[i].isAlive) {

                if (allEnemies[i].enemyId != 0) {
                    for (int j = 0; j < maxEnemyCount; ++j) {
                        if (!allEffects[i].var) {
                            allEffects[i] = {0, true, Rectangle{allEnemies[i].x, allEnemies[i].y, 180, 153}};
                        }
                    }
                }

                allEnemies[i].isAlive = true;

                allEnemies[i].enemyId = rand() % 2;

                if (id == 3) {
                    allEnemies[i].enemyId += 1;
                }

                bool collide = true;

                while (collide) {
                    allEnemies[i].x = (float) (rand() % GetScreenWidth()) + GetScreenWidth();

                    if (id == 3) {
                        allEnemies[i].y = (float) (rand() % (GetScreenHeight() - 260) + 260);

                        if (allEnemies[i].enemyId == 2) {
                            allEnemies[i].y = enemyRecList[allEnemies[i].enemyId][1].y;
                        }
                    } else {
                        allEnemies[i].y = (float) (rand() % (GetScreenHeight() - 217) + 217);

                        if (allEnemies[i].enemyId == 0) {
                            allEnemies[i].y = enemyRecList[allEnemies[i].enemyId][1].y;
                        }
                    }

                    for (int j = 0; j < currentEnemyCount; ++j) {
                        if (i != j) {
                            if (didEnemiesCollide(allEnemies[i], allEnemies[j])) {
                                collide = true;
                                break;
                            } else {
                                collide = false;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Enemies::drawEnemies(int id) {
    if (currentEnemyCount == maxEnemyCount) {
        for (int i = 0; i < currentEnemyCount; ++i) {
            if (allEnemies[i].isAlive) {

                if (allEnemies[i].x + enemyRecList[allEnemies[i].enemyId][1].width  < 0) {
                    allEnemies[i].isAlive = false;
                } else {
                    float enemySpeed = 2.0f;;

                    if (allEnemies[i].enemyId == 1) {
                        enemySpeed = 4.0f;
                    }

                    allEnemies[i].x -= enemySpeed;

                    Rectangle enemyDes = { allEnemies[i].x, allEnemies[i].y, enemyRecList[allEnemies[i].enemyId][1].width, enemyRecList[allEnemies[i].enemyId][1].height };

                    DrawTexturePro(enemies, enemyRecList[allEnemies[i].enemyId][0], enemyDes, origin, 0, RAYWHITE);
                }
            }
        }
    }
}

bool Enemies::didEnemiesCollide(oneEnemy enemy_1, oneEnemy enemy_2) {
    Rectangle enemyRec_1 = { enemy_1.x, enemy_1.y, enemyRecList[enemy_1.enemyId][1].width, enemyRecList[enemy_1.enemyId][1].height };
    Rectangle enemyRec_2 = { enemy_2.x, enemy_2.y, enemyRecList[enemy_2.enemyId][1].width, enemyRecList[enemy_2.enemyId][1].height };

    bool value = CheckCollisionRecs(enemyRec_1, enemyRec_2);

    return value;
}