//
// Created by Werwolf2 on 19.05.2021.
//
#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include <stdbool.h>
#include "raylib.h"

typedef struct tile
{
    bool airunit;       //if a unit on field, another unit can not stay on the field
    bool groundunit;

    bool groundblocked; //if field is blocked, a unit can not route through it
    bool airblocked;

    Texture2D texture;  //tile texture

    int x;
    int y;
    //int height;       //maybe add an height to the game later on
} tile;

typedef struct unit
{
    int ID;     //unit ID
    bool isair; //if airunit more dmg by flak

    float max_hp;       //max amount hp it can have
    float hp;           //current hp it has
    float armor;        //scales armorpenetration makes more dmg; not armorpen deals less dmg
    float dmg;          //base-dmg, calculated with armor, armorpen and hp
    float penetration;  //penetration multiplicator more dmg on armored stuff, less on unamored stuff

    int size;    //how many tiles it has, only important for buildings
    float speed; // 0 for buildings; else speed of travel (tiles per sec.?)
    int space;   // how many units it can store; units dont get dmg when under attack; units only die with death of holder if unit is an airship
    int requnits;// determines how many units(engineers, pop) needed to operate the unit/building

    bool dead;   //determines if unit is dead, what did you expect?!
} unit;

typedef struct player
{
    int ID;

    int x;      //coordinates of the base
    int y;

    int money;
    float wood;
    float stone;
    float coal;
    float ironore;
    float iron;
    float steel;

    float copperore;
    float copper;
    float aetherium;
    float aetheriumcon;

    float food;
    float foodcon;

    bool dead;
}player;

#endif