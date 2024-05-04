#include "Player.h"

Player::Player(int id) {
    this->id = id;

    switch (id) {
        case 1:
            character = LoadTexture("../resources/image/shark1.png");
            characterRec_1 = {0,0,323,99};
            characterRec_2 = {0,99,323,99};
            characterRec_eating = {323,0,323,99};
            characterDes = {817,392,323,99};

            break;

        case 2:
            character = LoadTexture("../resources/image/shark2.png");
            characterRec_1 = {0,0,387,119};
            characterRec_2 = {0,119,387,119};
            characterRec_eating = {387,0,387,119};
            characterDes = {817,392,387,119};

            break;

        case 3:
            character = LoadTexture("../resources/image/shark3.png");
            characterRec_1 = {0,0,489,193};
            characterRec_2 = {0,193,489,193};
            characterRec_eating = {489,0,489,193};
            characterDes = {817,392,489,193};

            break;

    }

}

void Player::drawUI() {
    DrawTexturePro(ui, uiBlueBackRec, uiBlueBackDes_1, origin, 0, RAYWHITE);

    uiHealthRec.width = (float)health * 201/100;;
    uiHealthDes.width = (float)health * 365/100;

    DrawTexturePro(ui, uiHealthRec, uiHealthDes, origin, 0, RAYWHITE);
    DrawTexturePro(ui, uiWhiteLineRec, uiWhiteLineDes, origin, 0, RAYWHITE);
    DrawTexturePro(ui, uiHeartRec, uiHeartDes, origin, 0, RAYWHITE);

    std::string t = std::to_string(health);
    const char *text = t.c_str();

    DrawTextPro(font, text, Vector2 { 232 , 55 }, origin, 0, 33, 0, WHITE);

    DrawTexturePro(ui, uiBlueBackRec, uiBlueBackDes_2, origin, 0, RAYWHITE);
    DrawTexturePro(ui, uiGrayBackRec, uiGrayBackDes, origin, 0, RAYWHITE);

    uiWhiteRec.width = (float)xp * 201/100;;
    uiWhiteDes.width = (float)xp * 200/100;

    DrawTexturePro(ui, uiWhiteRec, uiWhiteDes, origin, 0, RAYWHITE);

    std::string t_2 = "%" + std::to_string(xp);
    const char *text_2 = t_2.c_str();

    DrawTextPro(font,  text_2, Vector2 { 223 , 128 }, origin, 0, 33, 0, WHITE);
}

void Player::checkInput() {
    mousePos = GetMousePosition();

    if (mousePos.x >= 1920) {
        mousePos.x = 1920;
    } else if (mousePos.x <= 0) {
        mousePos.x = 0;
    }

    switch (id) {
        case 1:
            if (mousePos.y >= 1080) {
                mousePos.y = 1080;
            } else if (mousePos.y <= 0) {
                mousePos.y = 0;
            }

            break;

        case 2:
            if (mousePos.y >= 1080) {
                mousePos.y = 1080;
            } else if (mousePos.y <= 195) {
                mousePos.y = 195;
            }

            break;

        case 3:
            if (mousePos.y >= 1080) {
                mousePos.y = 1080;
            } else if (mousePos.y <= 260) {
                mousePos.y = 260;
            }

            break;
    }

    if (mousePos.x > characterDes.x) {
        characterMoveRight = true;
    } else {
        characterMoveRight = false;
    }

}

void Player::manageInput() {

    angle = atan2((mousePos.y - (characterDes.y)),(mousePos.x - (characterDes.x))) * RAD2DEG;

    characterDes.x += (mousePos.x - (characterDes.x))/speed;
    characterDes.y += (mousePos.y - (characterDes.y))/speed;

    if (animations.playerSharkAnimation() == 1) {
        characterRec = characterRec_1;
    } else {
        if (!playerEating) {
            characterRec = characterRec_2;
        } else {
            characterRec = characterRec_eating;
        }
    }

    if (characterMoveRight) {
        characterRec.height = characterDes.height;
    } else {
        characterRec.height = -characterDes.height;
    }

    //DrawRectangle(characterDes.x, characterDes.y, characterDes.width, characterDes.height, BLUE);
    //DrawCircle((int) (characterDes.x), (int) (characterDes.y), characterRec_hit.radius, RED);
}

void Player::drawPlayer() const {
    DrawTexturePro(character, characterRec, characterDes, Vector2 {characterRec.width - 20, 34}, angle, RAYWHITE);
}