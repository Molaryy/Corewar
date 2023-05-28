/*
** EPITECH PROJECT, 2023
** corewar/src/vm/helper.c
** File description:
** this will have helper functions for the vm
*/

#include "core.h"

void reset_cycle(info_corewar_t *info)
{
    if (info->vm.current_cycle >= info->vm.cycle_to_die) {
        info->vm.current_cycle = 0;
        info->vm.cycle_to_die -= (int) ((float) (info->vm.nbr_live / NBR_LIVE)
            - 0.5) * CYCLE_DELTA;
        info->vm.nbr_live = 0;
    }
}

void dump_memory(info_corewar_t *info)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 2 == 0)
            my_printf("%08X ", info->vm.memory[i]);
        if (i % 2 == 1)
            my_printf("%08X\n", info->vm.memory[i]);
    }
    my_putchar('\n');
}

void disp_last_live(info_corewar_t *info)
{
    int last_live_champ_index;
    int max = 0;

    for (int i = 0; i <= info->nbr_champions; i++) {
        if (info->champions[i].last_live_cycle >= max) {
            max = info->champions[i].last_live_cycle;
            last_live_champ_index = i;
        }
    }
    my_printf("The player %d(%s)has won.\n", info->champions
        [last_live_champ_index].prog_nbr, info->champions
        [last_live_champ_index].name);
}

int check_game_over(info_corewar_t *info)
{
    if (info->dump != -1 && info->vm.total_cycles >= info->dump) {
        dump_memory(info);
        disp_last_live(info);
        return TRUE;
    }
    reset_cycle(info);
    if (!(info->vm.nbr_live <= 0 && info->vm.cycle_to_die == 0))
        return FALSE;
    disp_last_live(info);
    return TRUE;
}
