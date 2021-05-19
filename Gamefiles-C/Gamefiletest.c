//
// Created by Werwolf2 on 14.05.2021.
//

#include <stdbool.h>
#include "windowsray.h"
#include "raylib.h"
//#include <stdio.h>

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    bool firstDraw = true;
    bool firstframe = true;
    Color iconcolor = { 255, 255, 255, 255 };

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - texture rectangle");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D scarfy = LoadTexture("../resources/scarfy.png");        // Texture loading
    Texture2D Icon = LoadTexture("../resources/GameIcon.png");

    Vector2 position = { ((float) GetScreenWidth())/ 2 - 50.0f, ((float) GetScreenHeight())/ 2 + 80.0f };
    Rectangle frameRec = { 0.0f, 0.0f, (float)scarfy.width/6, (float)scarfy.height };
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 8;            // Number of spritesheet frames shown by second

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    ToggleFullscreen();
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)scarfy.width/6;
        }
        SetLoadFileDataCallback()
        if (IsKeyDown(KEY_RIGHT)) framesSpeed++;
        else if (IsKeyDown(KEY_LEFT)) framesSpeed--;

        if (framesSpeed > MAX_FRAME_SPEED) framesSpeed = MAX_FRAME_SPEED;
        else if (framesSpeed < MIN_FRAME_SPEED) framesSpeed = MIN_FRAME_SPEED;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        if (firstframe)
            Sleep(5000);
        firstframe = false;
        ClearBackground(RAYWHITE);
        if (firstDraw == true)
        {
            iconcolor.a--;
            if(IsKeyPressed(KEY_Y) || iconcolor.a <= 50)
                firstDraw = false;
            else
            {
                DrawTexture(Icon, ((float) GetScreenWidth()) / 2 - Icon.width / 2, ((float) GetScreenHeight()) / 2 - Icon.height / 2, iconcolor);
                EndDrawing();
                continue;
            }
        }
        DrawTexture(scarfy, 15, 40, WHITE);
        DrawRectangleLines(15, 40, scarfy.width, scarfy.height, LIME);
        DrawRectangleLines(15 + (int)frameRec.x, 40 + (int)frameRec.y, (int)frameRec.width, (int)frameRec.height, RED);

        DrawText("FRAME SPEED: ", 165, 210, 10, BLUE);
        DrawText(TextFormat("%02i FPS", framesSpeed), 575, 210, 10, BLUE);
        DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, 240, 10, BLUE);

        for (int i = 0; i < MAX_FRAME_SPEED; i++)
        {
            if (i < framesSpeed) DrawRectangle(250 + 21*i, 205, 20, 20, RED);
            DrawRectangleLines(250 + 21*i, 205, 20, 20, MAROON);
        }

        DrawTextureRec(scarfy, frameRec, position, WHITE);  // Draw part of the texture

        DrawText("(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(scarfy);       // Texture unloading
    UnloadTexture(Icon);

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}