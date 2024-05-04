#include "Menu.h"
#include "Levels.h"
#include "Utilities.h"

int main () {
    srand(time(0));

    Utilities utilities;

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Angry Sharks");
    InitAudioDevice();

    //Çalışmıyor.
    Image icon = LoadImage("../resources/icon.psd");
    SetWindowIcon(icon);
    
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetWindowState(FLAG_VSYNC_HINT);

    int monitor = GetCurrentMonitor();

    if(GetMonitorWidth(monitor) == screenWidth && GetMonitorHeight(monitor) == screenHeight) {
        SetWindowState(FLAG_FULLSCREEN_MODE);
        ToggleFullscreen();
    }

    SetTargetFPS(60);

    int gameScreenWidth = 1920;
    int gameScreenHeight = 1080;

    RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);

    Menu menu;
    Levels level_1(1,Player(1), menu);
    Levels level_2(2,Player(2), menu);
    Levels level_3(3,Player(3), menu);

    PlayMusicStream(menu.ocean);
    PlayMusicStream(menu.menuMusic);

    while (!menu.exitGame) {
        UpdateMusicStream(menu.menuMusic);
        UpdateMusicStream(menu.ocean);

        SetMusicVolume(menu.menuMusic, menu.music_volume);
        SetMusicVolume(menu.ocean, 0);

        while (menu.init) {
            menu.raylib_animation();
        }

        BeginTextureMode(target);

        if(!menu.startGame) {
            if (!menu.info) {
                menu.draw();
            } else {
                menu.drawInfo();
            }

            menu.checkButton();
        }

        if (menu.startGame && menu.firstLevelStart) {
            level_1.levelInit();
        } else if (menu.startGame && menu.firstLevelComplete) {
            level_2.levelInit();
        } else if (menu.startGame && menu.secondLevelComplete) {
            level_3.levelInit();
        }

        EndTextureMode();

        BeginDrawing();

        ClearBackground(BLACK);

        float newScreenHeight = utilities.GetResizedScreenHeight((float)gameScreenWidth, (float)gameScreenHeight, (float)GetScreenWidth());

        Rectangle targetRec = {0, 0, static_cast<float>(target.texture.width), static_cast<float>(-target.texture.height)};
        Rectangle targetDes = {0, ((float)GetScreenHeight() - newScreenHeight)/2, (float)GetScreenWidth(), newScreenHeight};
        Vector2 origin = {0, 0};

        DrawTexturePro(target.texture, targetRec,targetDes, origin, 0, RAYWHITE);

        EndDrawing();
    }

    UnloadRenderTexture(target);

    UnloadMusicStream(menu.ocean);
    UnloadMusicStream(menu.menuMusic);
    CloseAudioDevice();
    CloseWindow();
}