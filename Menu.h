#ifndef KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_MENU_H
#define KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_MENU_H

#include "raylib.h"

class Menu {
public:
    Music
        menuMusic = LoadMusicStream("../resources/audio/music/menu_music.mp3"),
        ocean = LoadMusicStream("../resources/audio/music/ocean.mp3");

    Sound
        buttonSound = LoadSound("../resources/audio/sound/button.mp3");

    Texture2D
        transparent_black = LoadTexture("../resources/image/transparent_black.png"),
        menuSharks = LoadTexture("../resources/image/menu_sharks.png"),
        menuBackground = LoadTexture("../resources/image/background.png"),
        menuButtons = LoadTexture("../resources/image/buttons.png"),
        menuPanels = LoadTexture("../resources/image/panels.png"),
        infoScreen = LoadTexture("../resources/image/info_screen.png");

    Rectangle
        menuBackgroundRec = {0, 0, 1920, 1080},
        menuBackgroundDes = {0,0, 1920, 1080},

        soundButtonRec = {82, 415, 82, 83},
        muteButtonRec = {82, 332, 82, 83},
        soundButtonDes = {1561, 28, 100, 101},

        musicButtonRec = {82, 249, 82, 83},
        musicMuteButtonRec = {82, 166, 82, 83},
        musicButtonDes = {1682, 28, 100, 101},

        returnButtonRec = {246, 415, 82, 83},
        returnButtonDes = {50, 28, 100, 101},

        infoButtonRec = {420, 0, 92, 92},
        infoButtonDes = {1124, 881, 130, 130},

        levelButtonRecLight = {901, 114, 243, 114},
        levelButtonRecDark = { 901, 0, 243, 114 },

        firstLevelButtonDes = {1518, 337, 298, 144},
        secondLevelButtonDes = {1518, 492, 298, 144},
        thirdLevelButtonDes = {1518, 646, 298, 144},

        firstMenuSharkRec = {525, 0, 113, 36},
        firstMenuSharkDes = {1572, 379, 190, 69},

        secondMenuSharkRec = {393, 0, 132, 42},
        secondMenuSharkLineRec = {423, 81, 144, 52},
        secondMenuSharkLineDes = {1572, 529, 190, 69},

        thirdMenuSharkRec = {260, 0, 133, 52},
        thirdMenuSharkLineRec = {279, 81, 144, 63},
        thirdMenuSharkLineDes = {1572, 673, 190, 83};

    Vector2
        origin = {0, 0},
        mouse_pos = { 0, 0 };

    float sound_volume = 0.03;
    float music_volume = 0.03;

    bool init = true;
    bool exitGame = false;
    bool startGame = false;
    bool info = false;

    bool soundButton = true;
    bool musicButton = true;

    bool firstLevelStart = false;
    bool firstLevelComplete = false;
    bool secondLevelComplete = false;

    bool secondLevelShark = false;
    bool thirdLevelShark = false;

    //Raylib Animation Things//
    int logoPositionX = GetScreenWidth()/2 - 128;
    int logoPositionY = GetScreenHeight()/2 - 128;

    int framesCounter = 0;
    int letterCount = 0;

    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;
    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;

    int state = 0;
    float alpha = 1.0f;
    //--//

    void raylib_animation();
    void draw();
    void drawInfo();
    void checkButton();

};


#endif //KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_MENU_H
