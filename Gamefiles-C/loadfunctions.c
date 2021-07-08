#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <raylib.h>

player *load_player(float initlist[13], int ID)
{
	player *p;
    p = malloc(sizeof(player));
    if (p == NULL)
        return (NULL);
    p->x = initlist[0];
    p->y = initlist[1];
    p->money =(int)initlist[2];
    p->wood = initlist[3];
    p->stone = initlist[4];
    p->coal = initlist[5];
    p->ironore = initlist[6];
    p->iron = initlist[7];
    p->steel = initlist[8];
    p->copperore = initlist[9];
    p->copper = initlist[10];
    p->aetherium = initlist[11];
    p->food = initlist[12];
    p->ID = ID;
    p->dead = false;
    p->coalcon = 0;
    p->aetheriumcon = 0;
    p->foodcon = 0;
    return (p);
}
unit *load_unit(int ID, int uID)
{
    unit *u;
    u = malloc(sizeof(unit));
    if (u == NULL)
        return (NULL);
	u->dead = false;
    switch (uID)
    {
        case 0:
			u->isair = false;
            return (u);
        case 1:
			u->isair = false;
            return (u);
        case 3:
			u->isair = false;
            return (u);
        case 4:
			u->isair = false;
            return (u);
        case 5:
			u->isair = false;
            return (u);
        case 6:
			u->isair = false;
            return (u);
        case 7:	
			u->isair = false;
        	return (u);
        case 8:
			u->isair = false;
        	return (u);
        case 9:
			u->isair = false;
            return (u);
        case 10:
            u->isair = true;
            return (u);
        case 11:
            u->isair = true;
            return (u);
        case 12:
            u->isair = true;
            return (u);
        case 13:
            u->isair = true;
            return (u);
        default:
            free(u);
        	return (NULL);
    }
}
