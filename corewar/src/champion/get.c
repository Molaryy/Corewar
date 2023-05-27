/*
** EPITECH PROJECT, 2023
** corewar/src/champion/get.c
** File description:
** get functions for champions
*/

#include "core.h"

int get_champ_prog_nbr(info_corewar_t *info, int index)
{
    int res = 0;
    int max = 0;

    for (int i = 0; i <= info->nb_champions; i++) {
        if (info->champions[i].loaded_addr > max)
            max = info->champions[i].loaded_addr;
        if (max < index)
            res = info->champions[i].prog_nbr;
    }
    return res;
}
