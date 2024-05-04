#ifndef KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_PLAYER_H
#define KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_PLAYER_H

#include "raylib.h"
#include "Animations.h"
#include <iostream>
#include <string>
#include <cmath>

class Player {
public:
    Font
        font = LoadFont("../resources/fonts/font.ttf");
    Texture2D
        character,
        ui = LoadTexture("../resources/image/ui.png");

    Rectangle
        characterRec,
        characterRec_1,
        characterRec_2,
        characterRec_eating,
        characterRec_death,
        characterDes,

        uiBlueBackRec = { 0, 0, 251, 49 },
        uiWhiteLineRec = { 251, 0, 206, 23 },
        uiHealthRec = { 251, 23, 201, 18 },
        uiGrayBackRec = { 251, 41, 207, 21 },
        uiWhiteRec = { 251, 62, 201, 18 },
        uiHeartRec = { 457, 0, 40, 36 },

        uiBlueBackDes_1 = { 28, 28, 440, 85 },
        uiBlueBackDes_2 = { 83, 125, 329, 64 },
        uiWhiteLineDes = { 77, 53, 365, 41 },
        uiHealthDes = { 75, 56, 365, 32 },
        uiGrayBackDes = { 146, 161, 207, 21 },
        uiWhiteDes = { 149, 163, 200, 17 },
        uiHeartDes = { 45, 45, 60, 54 };

    Vector2
        origin = {0, 0},
        mousePos = { 0, 0 };

    Animations animations;

    int id;

    int health = 100;
    int xp = 0;

    float angle;
    float speed = 40;

    bool characterMoveRight = true;
    bool playerEating = false;

    Player(int id);
    void drawUI();
    void checkInput();
    void manageInput();
    void drawPlayer() const;
};


#endif //KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_PLAYER_H
