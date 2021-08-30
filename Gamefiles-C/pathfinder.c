//
// Created by Werwolf2 on 28.05.2021.
//
#include <stdlib.h>

typedef struct olist{
    int tile;
    int prio;
    struct olist *next;
    struct olist *prev;
}olist;

/* start of functions for olist */

olist *olist_init(int start)
{
	olist *p = malloc(sizeof(olist) * 1);
	if (p == NULL)
        return (1);    
    p->prio = 0;
    p->tile = start;
    return p;
}

int olist_prioadd(olist *list, int prio, int tile)
{
    olist *last = list;
    while (last->prio < prio)
        last = last->next;
    olist *p = malloc(sizeof(olist) * 1);
    if (p == NULL)
        return (1);
    last->next = p;

    p->prev = last;
    p->tile = tile;
    p->prio = prio;
}

olist *olist_rem(olist *list)
{
    olist *newlist = list->next;
    newlist->prev = 0;
    free(list);
    return newlist;
}

void olist_delete(olist *list)
{
    olist *last = list->next;
    while (last->next != NULL)
        last = last->next;
    olist *prev = last->prev;
    while (prev != NULL)
    {
        free(last);
        last = prev;
        prev = last->prev;
    }
    free(last);
    return;
}

void addposition(int position, int next, int **array, int prio, olist *open)
{
    for (int i = 2; i < 6; i++)
    {
        if (array[position][i] == 0)
            continue;
        array[position][i] = next;
        if (array[next][1] != 0)
            array[next][1] = position;
        break;
    }
    olist_prioadd(open, prio, next);

}

int distancecal(int start, int end, int position)
{
    if (end - position < 0)
        position = (end - position) * (-1);
    else
        position = end - position;
    if (end - start < 0)
        start = (end - position) * (-1);
    else
        start = end - position;
    if (start < position)
        return 0;
    else if (start == position)
        return 1;
    else
        return 2;
}

int **path(int *collmap, int **array, int start, int dest)
{
    /*
     * array[10001000][0] position
     * array[10001000][1] previous tile
     * array[10001000][2] next tile
     * array[10001000][3] next tile
     * array[10001000][4] next tile
     * array[10001000][5] next tile
     * array[10001000][6] \0
     *                  free   obtained
     * collmap[10001000] 0      1
     *
     * start 00010001
     * end   01000100
    */
    olist *open = olist_init(start);

    int position = start;
    int counter = 0;
    int right = position + 1;
    int left = position - 1;
    int up = position + 1000;
    int down = position - 1000;

    while(open != NULL)
    {
        position = open->tile;
        distancecal( position, dest, position + 1); //right
        distancecal( position, dest, position - 1); //left
        distancecal( position, dest, position + 1000); //up
        distancecal( position, dest, position - 1000); //down
    }

}