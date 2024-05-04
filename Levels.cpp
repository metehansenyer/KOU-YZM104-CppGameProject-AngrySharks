#include "Levels.h"

Levels::Levels(int id, Player player, Menu& menu) : player(player) {
    this->id = id;
    this->player = player;
    this->menu = menu;
    this->startGame = &menu.startGame;
    this->firstLevelStart = &menu.firstLevelStart;
    this->firstLevelComplete = &menu.firstLevelComplete;
    this->secondLevelComplete = &menu.secondLevelComplete;
    this->secondLevelShark = &menu.secondLevelShark;
    this->thirdLevelShark = &menu.thirdLevelShark;
    this->sound_volume = &menu.sound_volume;
    this->music_volume = &menu.music_volume;
    this->soundButton = &menu.soundButton;
    this->musicButton = &menu.musicButton;
}

void Levels::levelInit() {
    levelBackground();

    if (playerAlive) {
        if (!levelCompleted) {
            if (!pauseGame) {
                setVolume();

                hunts.initHunts(id);
                hunts.reInitHunts(id);
                hunts.drawHunts();

                if (id != 1) {
                    enemies.initEnemies(id);
                    enemies.reInitEnemies(id);
                    enemies.drawEnemies(id);
                }

                player.checkInput();
                player.manageInput();
                player.drawPlayer();
                player.drawUI();

                gameInPauseButton();
                checkGameInPauseButton();

                checkHuntCollisions(player, hunts);

                if (id != 1) {
                    checkEnemyCollisions(player, enemies);
                    drawEffects(player, enemies);
                }

            } else {
                setWaitVolume(true);

                pause();
                checkButton();
            }
        } else {
            setWaitVolume(false);

            if (id != 3) {
                completed();
                checkCompletedButton();
            } else {
                finished();
                checkFinishedButton();
            }
        }
    } else {
        setWaitVolume(false);

        dead();
        checkDeadButton();
    }

}

void Levels::levelBackground() {
    Texture2D levelBackground;

    switch (id) {
        case 1:
            levelBackground = firstLevelBackground;
            break;

        case 2:
            levelBackground = secondLevelBackground;
            break;

        case 3:
            levelBackground = thirdLevelBackground;
            break;
    }


    if (playerAlive) {
        if (!levelCompleted) {
            if (!pauseGame) {
                scrollingBack -= 2.0f;
            }
        }
    }

    if (scrollingBack <= (float)-levelBackground.width) {
        scrollingBack = 0;
    }

    ClearBackground(BLACK);

    DrawTextureV(levelBackground, Vector2 { scrollingBack, 0 }, RAYWHITE);
    DrawTextureV(levelBackground, Vector2 {  (float)levelBackground.width + scrollingBack, 0 }, RAYWHITE);
}

void Levels::gameInPauseButton() const {
    DrawTexturePro(menu.menuButtons, gameInPauseButtonRec, gameInPauseButtonDes, origin, 0, RAYWHITE);
}

void Levels::checkGameInPauseButton() {
    mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, gameInPauseButtonDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 164, 166, 82, 83 }, gameInPauseButtonDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            pauseGame = true;
        }
    }
}

void Levels::pause() const {
    DrawTextureV(transparent_black, origin, RAYWHITE);
    DrawTexturePro(menu.menuPanels, panelRec,panelDes, origin, 0, RAYWHITE);

    if (*soundButton) {
        DrawTexturePro(menu.menuButtons, menu.soundButtonRec, soundButtonDes, origin, 0, RAYWHITE);
    } else {
        DrawTexturePro(menu.menuButtons, menu.muteButtonRec, soundButtonDes, origin, 0, RAYWHITE);
    }

    if (*musicButton) {
        DrawTexturePro(menu.menuButtons, menu.musicButtonRec, musicButtonDes, origin, 0, RAYWHITE);
    } else {
        DrawTexturePro(menu.menuButtons, menu.musicMuteButtonRec, musicButtonDes, origin, 0, RAYWHITE);
    }

    DrawTexturePro(menu.menuButtons, mainButtonRec, mainButtonDes, origin, 0, RAYWHITE);
    DrawTexturePro(menu.menuButtons, menu.returnButtonRec, returnButtonDes, origin, 0, RAYWHITE);

}

void Levels::checkButton() {
    mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, soundButtonDes)) {
        if (*soundButton) {
            DrawTexturePro(menu.menuButtons, Rectangle { 0, 415, 82, 83 }, soundButtonDes, origin, 0, RAYWHITE);
        } else {
            DrawTexturePro(menu.menuButtons, Rectangle { 0, 332, 82, 83 }, soundButtonDes, origin, 0, RAYWHITE);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            if (*soundButton) {
                *sound_volume = 0;
                *soundButton = false;
            } else {
                *sound_volume = 0.03;
                *soundButton = true;
            }
        }
    } else if (CheckCollisionPointRec(mouse_pos, musicButtonDes)) {
        if (*musicButton) {
            DrawTexturePro(menu.menuButtons, Rectangle { 0, 249, 82, 83 }, musicButtonDes, origin, 0, RAYWHITE);
        } else {
            DrawTexturePro(menu.menuButtons, Rectangle { 0, 166, 82, 83 }, musicButtonDes, origin, 0, RAYWHITE);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            if (*musicButton) {
                *music_volume = 0;
                *musicButton = false;
            } else {
                *music_volume = 0.03;
                *musicButton = true;
            }
        }
    } else if (CheckCollisionPointRec(mouse_pos, mainButtonDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 164, 0, 82, 83 }, mainButtonDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            pauseGame = false;

            player.health = 100;
            player.xp = 0;

            hunts.currentHuntCount = 0;

            *startGame = false;
        }
    } else if (CheckCollisionPointRec(mouse_pos, returnButtonDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 164, 415, 82, 83 }, returnButtonDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            pauseGame = false;
        }
    }

}

void Levels::completed() const {
    DrawTextureV(transparent_black, origin, RAYWHITE);
    DrawTexturePro(menu.menuPanels, panelRec,panelDes, origin, 0, RAYWHITE);

    DrawTextureV(stars, starsDes, RAYWHITE);

    switch (id) {
        case 1:
            DrawTexturePro(shark2, shark2Rec, shark2Des, origin, 0, RAYWHITE);
            break;

        case 2:
            DrawTexturePro(shark3, shark3Rec, shark3Des, origin, 0, RAYWHITE);
            break;
    }

    DrawTexturePro(menu.menuButtons, mainButtonRec, mainButtonCompleteDes, origin, 0, RAYWHITE);
    DrawTexturePro(menu.menuButtons, playButtonRec, playButtonDes, origin, 0, RAYWHITE);

    DrawTextPro(player.font, "YOU EVOLVED!", Vector2 { 730 , 342 }, origin, 0, 70, 0, WHITE);
}

void Levels::checkCompletedButton() {
    mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, mainButtonCompleteDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 164, 0, 82, 83 }, mainButtonCompleteDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            player.health = 100;
            player.xp = 0;

            hunts.currentHuntCount = 0;

            levelCompleted = false;
            *startGame = false;

            switch (id) {
                case 1:
                    *firstLevelStart = false;
                    *firstLevelComplete = true;
                    *secondLevelComplete = false;

                    *secondLevelShark = true;

                    break;

                case 2:
                    *firstLevelStart = false;
                    *firstLevelComplete = false;
                    *secondLevelComplete = true;

                    *thirdLevelShark = true;

                    break;
            }

        }
    } else if (CheckCollisionPointRec(mouse_pos, playButtonDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 328, 92, 102, 102 }, playButtonDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            player.health = 100;
            player.xp = 0;

            hunts.currentHuntCount = 0;

            levelCompleted = false;

            switch (id) {
                case 1:
                    *firstLevelStart = false;
                    *firstLevelComplete = true;
                    *secondLevelComplete = false;

                    *secondLevelShark = true;

                    break;

                case 2:
                    *firstLevelStart = false;
                    *firstLevelComplete = false;
                    *secondLevelComplete = true;

                    *thirdLevelShark = true;

                    break;
            }
        }
    }
}

void Levels::finished() const {
    DrawTextureV(transparent_black, origin, RAYWHITE);
    DrawTexturePro(menu.menuPanels, finalPanelRec,finalPanelDes, origin, 0, RAYWHITE);

    DrawTexturePro(menu.menuButtons, mainButtonRec, mainButtonFinalDes, origin, 0, RAYWHITE);

    DrawTextPro(player.font, "YOU ARE THE WINNER!", Vector2 { 660, 445 }, origin, 0, 60, 0, WHITE);
}

void Levels::checkFinishedButton() {
    mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, mainButtonFinalDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 164, 0, 82, 83 }, mainButtonFinalDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            player.health = 100;
            player.xp = 0;

            hunts.currentHuntCount = 0;

            levelCompleted = false;
            *startGame = false;

            *firstLevelStart = false;
            *firstLevelComplete = false;
            *secondLevelComplete = false;
        }
    }
}

void Levels::dead() const {
    DrawTextureV(transparent_black, origin, RAYWHITE);
    DrawTexturePro(menu.menuPanels, finalPanelRec,finalPanelDes, origin, 0, RAYWHITE);

    DrawTexturePro(menu.menuButtons, mainButtonRec, mainButtonFinalDes, origin, 0, RAYWHITE);

    DrawTextPro(player.font, "HAHA LOSER!", Vector2 { 740, 445 }, origin, 0, 70, 0, WHITE);
}

void Levels::checkDeadButton() {
    mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, mainButtonFinalDes)) {
        DrawTexturePro(menu.menuButtons, Rectangle { 164, 0, 82, 83 }, mainButtonFinalDes, origin, 0, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (!IsSoundPlaying(buttonSound)) {
                PlaySound(buttonSound);
            }

            player.health = 100;
            player.xp = 0;

            hunts.currentHuntCount = 0;

            playerAlive = true;
            levelCompleted = false;
            *startGame = false;

            switch (id) {
                case 2:
                    *firstLevelStart = false;
                    *firstLevelComplete = false;
                    *secondLevelComplete = false;

                    *thirdLevelShark = false;

                    break;

                case 3:
                    *firstLevelStart = false;
                    *firstLevelComplete = false;
                    *secondLevelComplete = false;

                    break;

            }

        }
    }
}



void Levels::checkHuntCollisions(Player& playerShadow, Hunts& huntsShadow) {
    Rectangle playerShadowRec = playerShadow.characterDes;

    if (huntsShadow.currentHuntCount == huntsShadow.maxHuntCount) {
        for (int i = 0; i < huntsShadow.maxHuntCount; ++i) {
            int fishId = huntsShadow.allHunts[i].fishId + 1;
            float width = huntsShadow.fishRecList[fishId][0].width;
            float height = huntsShadow.fishRecList[fishId][0].height;

            Rectangle huntShadowRec = { huntsShadow.allHunts[i].x, huntsShadow.allHunts[i].y, width, height };

            if (CheckCollisionCircleRec(Vector2 { playerShadowRec.x, playerShadowRec.y}, 20, huntShadowRec)) {
                if (!IsSoundPlaying(eatingSound)) {
                    PlaySound(eatingSound);
                }

                playerShadow.playerEating = true;

                if (fishId == 9 || fishId == 6) {
                    huntsShadow.allHunts[i].isScared = false;
                } else {
                    huntsShadow.allHunts[i].isScared = true;
                }

                huntsShadow.allHunts[i].health -= 2;

                if (huntsShadow.allHunts[i].health == 0) {

                    if (fishId == 9) {
                        if (playerShadow.health < 100) {
                            if (!IsSoundPlaying(healSound)) {
                                PlaySound(healSound);
                            }

                            playerShadow.health += 10;
                        }
                    } else if (fishId == 6) {
                        if (!IsSoundPlaying(hitSound)) {
                            PlaySound(hitSound);
                        }

                        playerShadow.health -= 10;

                        if (playerShadow.health <= 0) {
                            playerAlive = false;
                        }
                    } else {
                        playerShadow.xp += 10;
                    }

                    playerShadow.playerEating = false;

                    if (playerShadow.xp >= 100) {
                        levelCompleted = true;

                        if (!IsSoundPlaying(victorySound)) {
                            PlaySound(victorySound);
                        }
                    }
                }
            }
        }
    }

}

void Levels::checkEnemyCollisions(Player &playerShadow, Enemies& enemiesShadow) {
    Rectangle playerShadowRec = playerShadow.characterDes;

    if (enemiesShadow.currentEnemyCount == enemiesShadow.maxEnemyCount) {
        for (int i = 0; i < enemiesShadow.currentEnemyCount; ++i) {
            int enemyId = enemiesShadow.allEnemies[i].enemyId;
            float width = enemiesShadow.enemyRecList[enemyId][0].width;
            float height = enemiesShadow.enemyRecList[enemyId][0].height;

            height += 200;


            Rectangle enemiesShadowRec = { enemiesShadow.allEnemies[i].x, enemiesShadow.allEnemies[i].y, width, height };

            if (CheckCollisionCircleRec(Vector2 { playerShadowRec.x, playerShadowRec.y}, 30, enemiesShadowRec)) {

                if (enemyId == 0) {
                    if (!enemiesShadow.allEnemies[i].damaged) {
                        if (!IsSoundPlaying(hitSound)) {
                            PlaySound(hitSound);
                        }

                        playerShadow.health -= 20;
                        enemiesShadow.allEnemies[i].damaged = true;
                    }
                } else {
                    if (!IsSoundPlaying(bombSound)) {
                        PlaySound(bombSound);
                    }
                    
                    playerShadow.health -= 10;
                    enemiesShadow.allEnemies[i].isAlive = false;
                }

                if (playerShadow.health <= 0) {
                    playerAlive = false;
                }

            }
        }
    }
}

void Levels::drawEffects(Player& playerShadow, Enemies& enemiesShadow) {
    for (int i = 0; i < enemiesShadow.maxEnemyCount; ++i) {
        if (enemiesShadow.allEffects[i].var) {
            if (enemiesShadow.allEffects[i].frame < 60) {
                //enemiesShadow.allEffects[i].effectDes.x = playerShadow.characterDes.x - 80;
                //enemiesShadow.allEffects[i].effectDes.y =playerShadow.characterDes.y - 80;
                enemiesShadow.allEffects[i].effectDes.width = 180 + (float) enemiesShadow.allEffects[i].frame;
                enemiesShadow.allEffects[i].effectDes.height = 153 + (float) enemiesShadow.allEffects[i].frame;

                enemiesShadow.allEffects[i].effectDes.x -= 2.0f;
                DrawTexturePro(enemiesShadow.enemies, enemiesShadow.enemyRecBombEffect, enemiesShadow.allEffects[i].effectDes, origin, 0, RAYWHITE);

                enemiesShadow.allEffects[i].frame++;
            } else {
                enemiesShadow.allEffects[i].var = false;
            }
        }
    }
}

void Levels::setVolume() const {
    SetMusicVolume(menu.menuMusic, 0);
    SetMusicVolume(menu.ocean, *sound_volume);
    SetSoundVolume(victorySound, *music_volume);
    SetSoundVolume(eatingSound, *sound_volume);
    SetSoundVolume(bombSound, *sound_volume);
    SetSoundVolume(hitSound, *sound_volume);
    SetSoundVolume(healSound, *sound_volume);
    SetSoundVolume(buttonSound, *sound_volume);
}

void Levels::setWaitVolume(bool control) const {
    if (control) {
        SetMusicVolume(menu.menuMusic, *music_volume);
    } else {
        SetMusicVolume(menu.menuMusic, 0);
    }

    SetMusicVolume(menu.ocean, 0);
    SetSoundVolume(victorySound, *sound_volume);
    SetSoundVolume(eatingSound, 0);
    SetSoundVolume(bombSound, 0);
    SetSoundVolume(hitSound, 0);
    SetSoundVolume(healSound, 0);
    SetSoundVolume(buttonSound, *sound_volume);
}