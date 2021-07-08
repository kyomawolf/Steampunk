#include <raylib.h>
#include "windowsray.h"
#include <stdio.h>
#include <stdbool.h>

int  DrawIcon(Color iconcolor, Texture2D Icon, Vector2 mid);

int main(void)
{
    int secondcounter = 60;
    int frames = 10;
    int curr_frame = 0;
    int framecounter = 0;
    bool iconshow = true;
    bool firstframe = true;
    Color iconcolor = {255, 255, 255, 255};

    InitWindow(GetScreenWidth(), GetScreenHeight(), "STEAMPUNK_GAME_TEST_V0.00.00.01");

    int screenwidth = GetScreenWidth();
    int screenheight = GetScreenHeight();

    Texture2D unit_one = LoadTexture("../resources/Grass.png");
    Texture2D Icon = LoadTexture("../resources/GameIcon.png");

    Vector2 mid = {(float)screenwidth / 2, (float)screenheight / 2};

    Rectangle unit_one_frame = {0.0f, 0.0f, (float)unit_one.width / 2,(float)unit_one.height / 6};
    SetTargetFPS(60);
    //starting Game
    ClearBackground(RAYWHITE);
    DrawIcon(iconcolor, Icon, mid);
    //Main Gameloop
    while(!WindowShouldClose()) //try while (1)\n{do}
    {
        if (secondcounter != 60) {
            secondcounter++;
            continue;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (curr_frame > 10)
            curr_frame = 0;
        if (curr_frame % 2 == 1)
            unit_one_frame.x = 1 * (float)unit_one.width / 2;
        else
            unit_one_frame.x = 0 * (float)unit_one.width / 2;
        unit_one_frame.y = (curr_frame / 2) * (float)unit_one.height;
        DrawTextureRec(unit_one, unit_one_frame, mid, WHITE);
        EndDrawing();
        curr_frame++;
        secondcounter = 0;

    }
    UnloadTexture(unit_one);
    UnloadTexture(Icon);
    CloseWindow();

    return 0;
}