/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** check_index
*/

#include "asm.h"

extern size_t check_start(char c, size_t start)
{
    return c == ':' ? 0 : start;
}

extern bool get_index(char c)
{
    return c != 'r' ? true : false;
}

static champ_t *fill_index(size_t j, size_t i, champ_t *champ, char **tab)
{
    if (!my_strcmp(tab[j], champ[i].paramName))
        return champ;
    switch (j) {
        case 0: champ[i].isIndex[0] = true; break;
        case 1:
            champ[i].isIndex[0] = get_index(champ[i].params[0][0]);
            champ[i].isIndex[1] = get_index(champ[i].params[1][0]);
                break;
        case 2:
            champ[i].isIndex[1] = get_index(champ[i].params[1][0]);
            champ[i].isIndex[2] = get_index(champ[i].params[2][0]);
            break;
        case 3: champ[i].isIndex[0] = true; break;
        case 4:
            champ[i].isIndex[0] = get_index(champ[i].params[0][0]);
            champ[i].isIndex[1] = get_index(champ[i].params[1][0]);
            break;
        case 5: champ[i].isIndex[0] = true; break;
    }
    return champ;
}

extern void check_index(champ_t *champ, size_t len)
{
    char *tab[] = {"zjump", "ldi", "sti", "fork", "lldi", "lfork",  NULL};

    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; tab[j]; j++)
            champ = fill_index(j, i, champ, tab);
    }
}
