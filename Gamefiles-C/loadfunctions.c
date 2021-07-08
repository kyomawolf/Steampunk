#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <raylib.h>

player *load_player(float initlist[13], int ID)		// inits A player with a given ID // RETURNS null || Player
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

unit *load_unit(int ID, int uID)		// inits unit with a given player-ID and a Unit-ID // RETURNS null || Unit
{
    unit *u;

    u = malloc(sizeof(unit));
    if (u == NULL)
        return (NULL);
	u->dead = false;
	switch (uID)						// sets startvalues
	{
		default:
		break;
	}
    switch (uID)						// checks for Airunit
    {
        case 0 ... 9:
			u->isair = false;
            return (u);
        case 10 ... 13:
            u->isair = true;
            return (u);
        default:
            free(u);
        	return (NULL);
    }
}

