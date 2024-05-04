#ifndef KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_HUNTS_H
#define KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_HUNTS_H

#include "raylib.h"
#include "Animations.h"
#include <cstdlib>
#include <ctime>

struct oneHunt {
    int fishId;
    float x;
    float y;
    int health = 100;
    bool isScared = false;
};

typedef oneHunt oneHunt;

class Hunts {
public:
    Animations animations;

    Texture2D
        fish_0,
        fish_1 = LoadTexture("../resources/image/fish_1.png"),
        fish_2 = LoadTexture("../resources/image/fish_2.png"),
        fish_3 = LoadTexture("../resources/image/fish_3.png"),
        fish_4 = LoadTexture("../resources/image/fish_4.png"),
        fish_5 = LoadTexture("../resources/image/fish_5.png"),
        fish_6 = LoadTexture("../resources/image/fish_6.png"),
        fish_7 = LoadTexture("../resources/image/fish_7.png"),
        fish_8 = LoadTexture("../resources/image/fish_8.png"),
        fish_healer = LoadTexture("../resources/image/fish_healer.png"),

        fishList[10] = { fish_0,fish_1, fish_2, fish_3, fish_4, fish_5, fish_6, fish_7, fish_8, fish_healer };

    Rectangle
        fishRec_0,

        fishRec_1_0 = { 0, 0, 104, 62 },
        fishRec_1_1 = { 104, 0, 103, 62 },

        fishRec_2_0 = { 0, 0, 111, 66 },
        fishRec_2_1 = { 111, 0, 107, 66 },

        fishRec_3_0 = { 0, 0, 111, 78 },
        fishRec_3_1 = { 111, 0, 111, 78 },

        fishRec_4_0 = { 0, 0, 112, 58 },
        fishRec_4_1 = { 112, 0, 112, 58 },

        fishRec_5_0 = { 0, 0, 159, 78 },
        fishRec_5_1 = { 159, 0, 159, 78 },

        fishRec_6_0 = { 0, 0, 116, 63 },
        fishRec_6_1 = { 116, 0, 116, 63 },

        fishRec_7_0 = { 0, 0, 100, 105 },
        fishRec_7_1 = { 100, 0, 100, 105 },

        fishRec_8_0 = { 0, 0, 93, 100 },
        fishRec_8_1 = { 93, 0, 93, 100 },

        fishRec_healer_0 = { 0, 0, 141, 78 },
        fishRec_healer_1 = { 141, 0, 141, 78 },

        fishRecList[10][2] = {fishRec_0, fishRec_0, fishRec_1_0, fishRec_1_1, fishRec_2_0, fishRec_2_1, fishRec_3_0, fishRec_3_1, fishRec_4_0, fishRec_4_1, fishRec_5_0, fishRec_5_1, fishRec_6_0, fishRec_6_1, fishRec_7_0, fishRec_7_1, fishRec_8_0, fishRec_8_1, fishRec_healer_0, fishRec_healer_1 };


    Vector2
        origin = { 0, 0 };


    oneHunt allHunts[10];

    int fishTypeCount = 9;
    int currentHuntCount = 0;
    int maxHuntCount = 10;

    float fishSpeed = 3.0f;

    bool fishCollide = false;

    void initHunts(int id);
    void reInitHunts(int id);
    void drawHunts();
    bool didFishesCollide( oneHunt fish_1, oneHunt fish_2);
};

#endif //KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_HUNTS_H
