#include "Menu.h"

void Menu::raylib_animation() {
    if (state == 0) {
        framesCounter++;

        if (framesCounter == 120) {
            state = 1;
            framesCounter = 0;
        }
    } else if (state == 1) {
        topSideRecWidth += 4;
        leftSideRecHeight += 4;

        if (topSideRecWidth == 256) {
            state = 2;
        }
    } else if (state == 2) {
        bottomSideRecWidth += 4;
        rightSideRecHeight += 4;

        if (bottomSideRecWidth == 256) {
            state = 3;
        }
    } else if (state == 3) {
        framesCounter++;

        if (framesCounter/12) {
            letterCount++;
            framesCounter = 0;
        }

        if (letterCount >= 10) {
            alpha -= 0.02f;

            if (alpha <= 0.0f) {
                alpha = 0.0f;
                state = 4;
            }
        }
    } else if (state == 4) {
        init = false;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (state == 0) {
        if ((framesCounter/15)%2) {
            DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
        }
    } else if (state == 1) {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
    } else if (state == 2) {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

        DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
    } else if (state == 3) {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));

        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));

        DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(RAYWHITE, alpha));

        DrawText(TextSubtext("raylib", 0, letterCount), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50, Fade(BLACK, alpha));
    }

    EndDrawing();
}

void Menu::draw() {
    ClearBackground(BLACK);

    mouse_pos = GetMousePosition();

    DrawTexturePro(menuBackground, menuBackgroundRec, menuBackgroundDes, origin, 0, RAYWHITE);

    if (soundButton) {
        DrawTexturePro(menuButtons, soundButtonRec, soundButtonDes, origin, 0, RAYWHITE);
    } else {
        DrawTexturePro(menuButtons, muteButtonRec, soundButtonDes, origin, 0, RAYWHITE);
    }

    if (musicButton) {
        DrawTexturePro(menuButtons, musicButtonRec, musicButtonDes, origin, 0, RAYWHITE);
    } else {
        DrawTexturePro(menuButtons, musicMuteButtonRec, musicButtonDes, origin, 0, RAYWHITE);
    }

    DrawTexturePro(menuButtons, returnButtonRec, returnButtonDes, origin, 0, RAYWHITE);
    DrawTexturePro(menuButtons, infoButtonRec, infoButtonDes, origin, 0, RAYWHITE);

    DrawTexturePro(menuPanels, levelButtonRecDark, firstLevelButtonDes, origin, 0, RAYWHITE);
    DrawTexturePro(menuPanels, levelButtonRecDark, secondLevelButtonDes, origin, 0, RAYWHITE);
    DrawTexturePro(menuPanels, levelButtonRecDark, thirdLevelButtonDes, origin, 0, RAYWHITE);

    DrawTexturePro(menuSharks, firstMenuSharkRec, firstMenuSharkDes, origin, 0, RAYWHITE);

    if (!secondLevelShark) {
        DrawTexturePro(menuSharks, secondMenuSharkLineRec, secondMenuSharkLineDes, origin, 0, RAYWHITE);
    } else {
        DrawTexturePro(menuSharks, secondMenuSharkRec, secondMenuSharkLineDes, origin, 0, RAYWHITE);
    }

    if (!thirdLevelShark) {
        DrawTexturePro(menuSharks, thirdMenuSharkLineRec, thirdMenuSharkLineDes, origin, 0, RAYWHITE);
    } else {
        DrawTexturePro(menuSharks, thirdMenuSharkRec, thirdMenuSharkLineDes, origin, 0, RAYWHITE);
    }

};

void Menu::drawInfo() {
    DrawTexturePro(infoScreen, Rectangle {0, 0, 854, 480}, Rectangle { 0, 0, 1920, 1080}, origin, 0, RAYWHITE);
    DrawTexturePro(menuButtons, returnButtonRec, returnButtonDes, origin, 0, RAYWHITE);
}

void Menu::checkButton() {
    SetSoundVolume(buttonSound, sound_volume);

    mouse_pos = GetMousePosition();

    if (!info) {
        if (CheckCollisionPointRec(mouse_pos, soundButtonDes)) {
            if (soundButton) {
                DrawTexturePro(menuButtons, Rectangle { 0, 415, 82, 83 }, soundButtonDes, origin, 0, RAYWHITE);
            } else {
                DrawTexturePro(menuButtons, Rectangle { 0, 332, 82, 83 }, soundButtonDes, origin, 0, RAYWHITE);
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                if (soundButton) {
                    sound_volume = 0;
                    soundButton = false;
                } else {
                    sound_volume = 0.03;
                    soundButton = true;
                }
            }
        } else if (CheckCollisionPointRec(mouse_pos, musicButtonDes)) {
            if (musicButton) {
                DrawTexturePro(menuButtons, Rectangle { 0, 249, 82, 83 }, musicButtonDes, origin, 0, RAYWHITE);
            } else {
                DrawTexturePro(menuButtons, Rectangle { 0, 166, 82, 83 }, musicButtonDes, origin, 0, RAYWHITE);
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                if (musicButton) {
                    music_volume = 0;
                    musicButton = false;
                } else {
                    music_volume = 0.03;
                    musicButton = true;
                }
            }
        } else if (CheckCollisionPointRec(mouse_pos, returnButtonDes)) {
            DrawTexturePro(menuButtons, Rectangle { 164, 415, 82, 83 }, returnButtonDes, origin, 0, RAYWHITE);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                exitGame = true;
            }
        } else if (CheckCollisionPointRec(mouse_pos, infoButtonDes)) {
            DrawTexturePro(menuButtons, Rectangle { 328, 0, 92, 92 }, infoButtonDes, origin, 0, RAYWHITE);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                info = true;
            }
        } else if (CheckCollisionPointRec(mouse_pos, firstLevelButtonDes)) {
            DrawTexturePro(menuPanels, levelButtonRecLight, firstLevelButtonDes, origin, 0, RAYWHITE);
            DrawTexturePro(menuSharks, firstMenuSharkRec, firstMenuSharkDes, origin, 0, RAYWHITE);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                startGame = true;
                firstLevelStart = true;
                firstLevelComplete = false;
                secondLevelComplete = false;
            }
        } else if (CheckCollisionPointRec(mouse_pos, secondLevelButtonDes)) {
            if (secondLevelShark) {
                DrawTexturePro(menuPanels, levelButtonRecLight, secondLevelButtonDes, origin, 0, RAYWHITE);
                DrawTexturePro(menuSharks, secondMenuSharkRec, secondMenuSharkLineDes, origin, 0, RAYWHITE);
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                if (secondLevelShark) {
                    startGame = true;
                    firstLevelStart = false;
                    firstLevelComplete = true;
                    secondLevelComplete = false;
                }
            }
        } else if (CheckCollisionPointRec(mouse_pos, thirdLevelButtonDes)) {
            if (thirdLevelShark) {
                DrawTexturePro(menuPanels, levelButtonRecLight, thirdLevelButtonDes, origin, 0, RAYWHITE);
                DrawTexturePro(menuSharks, thirdMenuSharkRec, thirdMenuSharkLineDes, origin, 0, RAYWHITE);
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                if (thirdLevelShark) {
                    startGame = true;
                    firstLevelStart = false;
                    firstLevelComplete = false;
                    secondLevelComplete = true;
                }
            }
        }
    } else {
        if (CheckCollisionPointRec(mouse_pos, returnButtonDes)) {
            DrawTexturePro(menuButtons, Rectangle { 164, 415, 82, 83 }, returnButtonDes, origin, 0, RAYWHITE);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!IsSoundPlaying(buttonSound)) {
                    PlaySound(buttonSound);
                }

                info = false;
            }
        }
    }
};
