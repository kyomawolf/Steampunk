//
// Created by Werwolf2 on 14.05.2021.
//
#include <raylib.h>
#include "windowsray.h"

int DrawIcon(Color iconcolor, Texture2D Icon, Vector2 mid)
{
    Sleep(10);

    while (1)
    {
        if (iconcolor.a < 10)
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(Icon, (float)(mid.x - (Icon.width / 2)), (float)(mid.y - (Icon.height / 2)), iconcolor);
        iconcolor.a--;
        EndDrawing();
    }
}
