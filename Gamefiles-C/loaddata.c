//
// Created by Werwolf2 on 19.05.2021.
//

#include "raylib.h"         //rayPlayAudio
//#include "windowsray.h"
#include "structs.h"
#include <stdio.h>

int load_menu_textures(Texture2D list[]);
int load_game_textures(Texture2D list[]);
int load_player(player *p);
int load_units(unit *p);
int load_tiles(tile *t);
int load_save(FILE *savegame);
int load_settings(FILE *settings);