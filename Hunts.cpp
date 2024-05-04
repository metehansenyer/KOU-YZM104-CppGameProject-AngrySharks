#include "Hunts.h"

void Hunts::initHunts(int id) {
    if (currentHuntCount < maxHuntCount) {

        if (!fishCollide) {
            int fishId = rand() % fishTypeCount;

            bool fishIdControl = false;

            while (!fishIdControl) {
                if (id == 1) {
                    if (fishId == 8 || fishId == 5) {
                        fishId = rand() % fishTypeCount;
                        continue;
                    } else {
                        fishIdControl = true;
                    }
                } else {
                    fishIdControl = true;
                }
            }

            int x = rand() % GetScreenWidth() + GetScreenWidth();

            int y;

            switch (id) {
                case 1:
                    y = rand() % GetScreenHeight();
                    break;

                case 2:
                    y = rand() % (GetScreenHeight() - 217) + 217;
                    break;

                case 3:
                    y = rand() % (GetScreenHeight() - 260) + 260;
                    break;
            }

            oneHunt fish = { fishId, (float) x, (float) y };

            allHunts[currentHuntCount] = fish;

            currentHuntCount++;

            if(currentHuntCount == maxHuntCount) {
                for (int i = 0; i < currentHuntCount; ++i) {
                    for (int j = 0; j < currentHuntCount; ++j) {
                        if (i != j) {
                            if (didFishesCollide(allHunts[i], allHunts[j])) {
                                fishCollide = true;
                                break;
                            }
                        }
                    }
                }
            }
        } else {
            currentHuntCount = 0;
            fishCollide = false;
        }

    }
}

void Hunts::reInitHunts(int id) {
    if (currentHuntCount == maxHuntCount) {
        for (int i = 0; i < maxHuntCount; ++i) {
            if (allHunts[i].health == 0 || allHunts[i].health == -500) {
                allHunts[i].fishId = rand() % fishTypeCount;

                bool fishIdControl = false;

                while (!fishIdControl) {
                    if (id == 1) {
                        if (allHunts[i].fishId == 8 || allHunts[i].fishId == 5) {
                            allHunts[i].fishId = rand() % fishTypeCount;
                            continue;
                        } else {
                            fishIdControl = true;
                        }
                    } else {
                        fishIdControl = true;
                    }
                }

                allHunts[i].health = 100;
                allHunts[i].x = (float) GetScreenWidth() + fishRecList[allHunts[i].fishId][0].width;

                bool controlY = true;

                while (controlY) {

                    switch (id) {
                        case 1:
                            allHunts[i].y = rand() % GetScreenHeight();
                            break;

                        case 2:
                            allHunts[i].y = rand() % (GetScreenHeight() - 217) + 217;
                            break;

                        case 3:
                            allHunts[i].y = rand() % (GetScreenHeight() - 260) + 260;
                            break;
                    }

                    for (int j = 0; j < maxHuntCount; ++j) {
                        if (i != j) {
                            if (didFishesCollide(allHunts[i], allHunts[j])) {
                                break;
                            } else if (j == maxHuntCount - 1) {
                                controlY = false;
                                break;
                            } else {
                                switch (id) {
                                    case 1:
                                        allHunts[i].y = rand() % GetScreenHeight();
                                        break;

                                    case 2:
                                        allHunts[i].y = rand() % (GetScreenHeight() - 217) + 217;
                                        break;

                                    case 3:
                                        allHunts[i].y = rand() % (GetScreenHeight() - 260) + 260;
                                        break;
                                }

                                controlY = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Hunts::drawHunts() {
    if (currentHuntCount == maxHuntCount) {
        for (int i = 0; i < maxHuntCount; ++i) {
            if (allHunts[i].health > 0) {
                int fishId = allHunts[i].fishId + 1;
                Texture2D fish = fishList[fishId];
                Rectangle fishRec, fishRecTemp;

                if (animations.huntsFishAnimation() == 1) {
                    fishRec = fishRecList[fishId][0];
                    fishRecTemp = fishRecList[fishId][0];
                } else {
                    fishRec = fishRecList[fishId][1];
                    fishRecTemp = fishRecList[fishId][1];
                }

                if (allHunts[i].x + fishRec.width  < 0) {
                    allHunts[i].health = -500;
                }

                if (!allHunts[i].isScared) {
                    allHunts[i].x -= fishSpeed;
                } else {
                    if (allHunts[i].x > (float) GetScreenWidth() + fishRec.width) {
                        allHunts[i].isScared = false;
                    }

                    allHunts[i].x += fishSpeed;
                    fishRec.width = -fishRecTemp.width;
                }

                Rectangle fishDes = { allHunts[i].x, allHunts[i].y, fishRecTemp.width, fishRecTemp.height };

                DrawTexturePro(fish, fishRec, fishDes, origin, 0, RAYWHITE);
            }
        }
    }
}

bool Hunts::didFishesCollide( oneHunt fish_1, oneHunt fish_2) {
    Rectangle fishRec_1 = { fish_1.x, fish_1.y, (float) fishList[fish_1.fishId].width, (float) fishList[fish_1.fishId].height};
    Rectangle fishRec_2 = { fish_2.x, fish_2.y, (float) fishList[fish_2.fishId].width, (float) fishList[fish_2.fishId].height};

    bool value = CheckCollisionRecs(fishRec_1, fishRec_2);

    return value;
}
