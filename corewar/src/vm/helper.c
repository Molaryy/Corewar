/*
** EPITECH PROJECT, 2023
** corewar/src/vm/helper.c
** File description:
** this will have helper functions for the vm
*/

#include "core.h"

int check_game_over(info_corewar_t *info)
{
    int nbr_alive = 0;
    int last_live_champ_index;

    for (int i = 0; i < info->nbr_champions; i++) {
        if (info->champions[i].live > NBR_LIVE) {
            nbr_alive++;
            last_live_champ_index = i;
        }
    }
    if (nbr_alive == 1) {
        my_printf("The player %d(%s)has won.\n", info->champions
            [last_live_champ_index].prog_nbr, info->champions
            [last_live_champ_index].name);
        return TRUE;
    }
    return nbr_alive <= 0 ? TRUE : FALSE;
}