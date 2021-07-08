//
// Created by Werwolf2 on 19.05.2021.
//

#include <raylib.h>         //rayPlayAudio
//#include "windowsray.h"
#include "structs.h"
#include <stdio.h>

int load_menu_textures(Texture2D list[]);
int load_game_textures(Texture2D list[]);
player load_player(float initstat[13], int ID);
unit load_units(int ID, int uID);
tile load_tiles(tile *t);
int load_save(FILE *savegame);
int load_settings(FILE *settings);