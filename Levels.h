#ifndef KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_LEVELS_H
#define KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_LEVELS_H

#include "raylib.h"
#include "Menu.h"
#include "Player.h"
#include "Hunts.h"
#include "Enemies.h"

class Levels {
public:
    Sound
        buttonSound = LoadSound("../resources/audio/sound/button.mp3"),
        healSound = LoadSound("../resources/audio/sound/heal.mp3"),
        hitSound = LoadSound("../resources/audio/sound/hit.mp3"),
        victorySound = LoadSound("../resources/audio/sound/victory.mp3"),
        eatingSound = LoadSound("../resources/audio/sound/eating.mp3"),
        bombSound = LoadSound("../resources/audio/sound/bomb.mp3");

    Texture2D
        transparent_black = LoadTexture("../resources/image/transparent_black.png"),
        stars = LoadTexture("../resources/image/stars.png"),

        firstLevelBackground = LoadTexture("../resources/image/level_1.png"),

        secondLevelBackground = LoadTexture("../resources/image/level_2.png"),
        shark2 = LoadTexture("../resources/image/shark2.png"),

        thirdLevelBackground = LoadTexture("../resources/image/level_3.png"),
        shark3 = LoadTexture("../resources/image/shark3.png");;

    Rectangle
        panelRec = {0, 0,451, 329,},
        panelDes = {560, 260, 800, 560},

        finalPanelRec = { 452, 2, 449, 274 },
        finalPanelDes = { 537, 283, 846, 514 },

        mainButtonRec = {246, 0, 82, 83},
        mainButtonDes = {885, 580, 150, 152},
        mainButtonCompleteDes = { 826, 629, 110, 111 },
        mainButtonFinalDes = { 903, 566, 115, 116 },

        gameInPauseButtonRec = {246, 166, 82, 83},
        gameInPauseButtonDes = {75, 839, 150, 161},

        returnButtonDes = {1252, 220, 150, 152},
        soundButtonDes = {735, 385, 150, 152},
        musicButtonDes = {1035, 385, 150, 152},

        playButtonRec = {430, 92,102, 102 },
        playButtonDes = {996, 627, 115, 115},

        shark2Rec = {0,0,387,119},
        shark2Des = { 767, 440, 387, 119 },

        shark3Rec = {0,0,489,193},
        shark3Des = { 767, 440, 387, 119 };

    Vector2
        starsDes = { 709, 386 },

        origin = {0, 0},
        mouse_pos {0, 0};

    int id;
    Player player;
    Menu menu;
    Hunts hunts;
    Enemies enemies;

    bool *startGame;
    bool *firstLevelStart;
    bool *firstLevelComplete;
    bool *secondLevelComplete;
    bool *secondLevelShark;
    bool *thirdLevelShark;

    bool playerAlive = true;
    bool pauseGame = false;
    bool levelCompleted = false;

    float scrollingBack = 0.0f;

    bool *soundButton;
    bool *musicButton;

    float *sound_volume;
    float *music_volume;

    Levels(int id, Player player, Menu& menu);
    void levelInit();
    void levelBackground();

    void checkHuntCollisions(Player& playerShadow, Hunts& huntsShadow);
    void checkEnemyCollisions(Player& playerShadow, Enemies& enemiesShadow);

    void dead() const;
    void checkDeadButton();

    void pause() const;
    void checkButton();

    void completed() const;
    void checkCompletedButton();

    void finished() const;
    void checkFinishedButton();

    void gameInPauseButton() const;
    void checkGameInPauseButton();

    void drawEffects(Player& playerShadow, Enemies& enemiesShadow);

    void setVolume() const;
    void setWaitVolume(bool control) const;
};


#endif //KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_LEVELS_H
